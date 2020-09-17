
#include <stdio.h>
#include <stdlib.h>

#include "game.h"

#include "game_functions.h"

const int   PLAYER_WIDTH        = 5;     // px
const int   PLAYER_HEIGHT       = 15;     // px
const float BALL_RADIUS         = 4.f;

// INTERNAL VALUES
const int   SCREEN_PADDING      = 15;    // px
const float PLAYER_SPEED        = 120.f; // px/s

void game_init(game_t* game, int width, int height)
{
    *game = (game_t){ .width = width, .height = height };

    // Init player
    game->player1.x = 0 + SCREEN_PADDING;
    game->player1.y = height/2;

    game->player2.x = width - SCREEN_PADDING - PLAYER_WIDTH;
    game->player2.y = height/2;
    
    // Init Ball
    
    game->ball.x = width/2;
    game->ball.y = height/2;
    game->ball.isLeft = true;

    game->ball.xSpeed = 1.f;
    game->ball.ySpeed = 4.f;
}

void game_destroy(game_t* game)
{
    // Nothing to do
}

void game_update(game_t* game, const game_inputs_t* inputs)
{
    // Collisions
    ball_collision(game);
    ball_collision_player(game);
    
    // Player update
    move_player(game, inputs);
    // Ball update
    move_ball(game, inputs);
}

