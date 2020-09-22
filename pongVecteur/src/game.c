#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "game.h"
#include "vector2.h"
#include "game_functions.h"
//#include "referantial.h"

const int   PLAYER_WIDTH        = 5;     // px
const int   PLAYER_HEIGHT       = 15;     // px
const float BALL_RADIUS         = 4.f;

// INTERNAL VALUES
const int   SCREEN_PADDING      = 15;    // px
const float PLAYER_SPEED        = 150.f; // px/s<
const float BALL_SPEED          = 2.f;

void game_init(game_t* game, int width, int height)
{
    srand(time(NULL));

    *game = (game_t){ .width = width, .height = height };

    game->isGameStart = false;

    //game->i = create_vector(0, 1);
    //game->j = create_vector(1, 0);

    // Init player
    {
        game->player1.playerPos = create_vector(0 + SCREEN_PADDING, height / 2 + PLAYER_HEIGHT / 2);
        game->player2.playerPos = create_vector(width - SCREEN_PADDING - PLAYER_WIDTH, height / 2 + PLAYER_HEIGHT / 2);
    }
    
    // Init Ball and local referantial
    {
        game->ball.ballPos = create_vector(width / 2, height / 2);

        game->ball.angle = 0 * (M_PI / 180);//random_float(-75.f, 75.f) * (PI / 180);

        game->ball.ballDir.x = cosf(game->ball.angle) * BALL_SPEED;
        game->ball.ballDir.y = sinf(game->ball.angle) * BALL_SPEED;
    }
}

void game_destroy(game_t* game)
{
    // Nothing to do
}

void game_update(game_t* game, const game_inputs_t* inputs)
{
    if (inputs->buttons[BUTTON_SPACE])
    {
        game->isGameStart = true;

        game->ball.angle = (random_float(-45.f, 45.f) + (180 * (rand() % 2))) * (M_PI / 180);

        game->ball.ballDir.x = cosf(game->ball.angle) * BALL_SPEED;
        game->ball.ballDir.y = sinf(game->ball.angle) * BALL_SPEED;
    }
    // Collisions
    ball_collision(game);
    ball_collision_player(game);
    
    if (game->isGameStart)
    {
        // Player update
        move_player(game, inputs);
        // Ball update
        move_ball(game, inputs);
    }
}

