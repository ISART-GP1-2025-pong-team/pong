
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "game.h"
#include <time.h>

float random_float(float min, float max)
{
    srand(time(NULL));
    return min + (float) rand() / (RAND_MAX/(max - min));
}

float clamp(float x, float minValue, float maxValue)
{
    if (x < minValue)
        return minValue;
    else if (x > maxValue)
        return maxValue;
    else
        return x;
}

bool point_inside_rect(float x, float y, float rx, float ry, float rw, float rh)
{
    return (x >= rx && x < rx + rw) &&
           (y >= ry && y < ry + rh);
}

// Move player using inputs (LEFT,RIGHT) and PLAYER_SPEED
// Player should stay inside the screen (use SCREEN_PADDING)
void move_player(game_t* game, const game_inputs_t* inputs)
{
    if (inputs->buttons[BUTTON_W])
        game->player1.y -= inputs->deltaTime * PLAYER_SPEED;
    if (inputs->buttons[BUTTON_S])
        game->player1.y += inputs->deltaTime * PLAYER_SPEED;
    
    if (inputs->buttons[BUTTON_UP])
        game->player2.y -= inputs->deltaTime * PLAYER_SPEED;
    if (inputs->buttons[BUTTON_DOWN])
        game->player2.y += inputs->deltaTime * PLAYER_SPEED;
    
    game->player1.y = clamp(game->player1.y, 0, game->height - PLAYER_HEIGHT);
    game->player2.y = clamp(game->player2.y, 0, game->height - PLAYER_HEIGHT);
}

void reset_ball(game_t* game)
{
    game->ball.x = game->width / 2;
    game->ball.y = game->height / 2;
    game->ball.isLeft = true;

    game->ball.xSpeed = 3;
    game->ball.ySpeed = 1;
}

void ball_collision_player(game_t* game)
{
    if (!game->ball.isLeft)
    {
        if     (game->ball.y  - BALL_RADIUS >= game->player1.y && game->ball.y + BALL_RADIUS <= game->player1.y + PLAYER_HEIGHT)
        {
            if (game->ball.x  - BALL_RADIUS <= game->player1.x + PLAYER_WIDTH && game->ball.x >= game->player1.x)
            {
                game->ball.xSpeed *= -1;
                game->ball.isLeft = true;
            }
        }
    }
    
    if (game->ball.isLeft)
    {
        if     (game->ball.y - BALL_RADIUS >= game->player2.y && game->ball.y + BALL_RADIUS <= game->player2.y + PLAYER_HEIGHT)
        {
            if (game->ball.x  + BALL_RADIUS >= game->player2.x && game->ball.x <= game->player2.x + PLAYER_WIDTH)
            {
                game->ball.xSpeed *= -1;
                game->ball.isLeft = false;
            }
        }
    }
}

void ball_collision(game_t* game)
{
    if (game->ball.y - BALL_RADIUS <= 0)
        game->ball.ySpeed -= -1;
    if (game->ball.y + BALL_RADIUS >= game->height)
        game->ball.ySpeed *= -1;

    if (game->ball.x <= 0.f)
        reset_ball(game);
    if (game->ball.x + BALL_RADIUS * 2.f >= game->width)
        reset_ball(game);
}

void move_ball(game_t* game, const game_inputs_t* inputs)
{
    game->ball.x += game->ball.xSpeed;
    game->ball.y += game->ball.ySpeed;
}

/*// Check if the player is hit by a bullet using bullet position and PLAYER_WIDTH/PLAYER_HEIGHT
bool player_is_hit_by_ball(player_t* player, bullet_t* bullet)
{
    	return point_inside_rect(ball->x, bullet->y, player->x - PLAYER_WIDTH/2, player->y - PLAYER_HEIGHT/2, PLAYER_WIDTH, PLAYER_HEIGHT);
}*/
