
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "vector2.h"
#include "game.h"
#include "intersection.h"

float random_float(float min, float max)
{
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

bool point_inside_rect(float x, float y, float y2, float rx, float ry, float rw, float rh)
{
    return (x >= rx && x < rx + rw) &&
           (y >= ry && y2 < ry + rh);
}

void move_player(game_t* game, const game_inputs_t* inputs)
{
    // Dans ref mathematique
    if (inputs->buttons[BUTTON_W])
        game->player1.playerPos.y += inputs->deltaTime * PLAYER_SPEED;
    if (inputs->buttons[BUTTON_S])
        game->player1.playerPos.y -= inputs->deltaTime * PLAYER_SPEED;
    
    if (inputs->buttons[BUTTON_UP])
        game->player2.playerPos.y += inputs->deltaTime * PLAYER_SPEED;
    if (inputs->buttons[BUTTON_DOWN])
        game->player2.playerPos.y -= inputs->deltaTime * PLAYER_SPEED;
    
    game->player1.playerPos.y = clamp(game->player1.playerPos.y, 0 + PLAYER_HEIGHT, game->height);
    game->player2.playerPos.y = clamp(game->player2.playerPos.y, 0 + PLAYER_HEIGHT, game->height);
}

void reset_ball(game_t* game)
{
    game->ball.ballPos.x = game->width / 2;
    game->ball.ballPos.y = game->height / 2;
    game->ball.isLeft = random_float(1, 2);

    if (game->ball.isLeft >= 1.5f)
    {
        game->ball.ballDir.x *= -1;
    }
}

void reset_player(game_t* game)
{
    game->player1.playerPos.x = 0 + SCREEN_PADDING;
    game->player1.playerPos.y = game->height/2;

    game->player2.playerPos.x = game->width - SCREEN_PADDING - PLAYER_WIDTH;
    game->player2.playerPos.y = game->height/2;
}

void reset_game(game_t* game)
{
    reset_ball(game);
    reset_player(game);
    game->isGameStart = false;
}

void ball_collision_player(game_t* game)
{
    bool isCollisionP1 = circle_segment_intersect((circle2_t) {game->ball.ballPos, BALL_RADIUS}, 
                                                  (segment2_t) {create_vector(game->player1.playerPos.x + PLAYER_WIDTH, game->player1.playerPos.y),
                                                                create_vector(game->player1.playerPos.x + PLAYER_WIDTH, game->player1.playerPos.y + PLAYER_HEIGHT)});

    bool isCollisionP2 = circle_segment_intersect((circle2_t) {game->ball.ballPos, BALL_RADIUS}, 
                                                  (segment2_t) {create_vector(game->player2.playerPos.x/* + PLAYER_WIDTH*/, game->player2.playerPos.y),
                                                                create_vector(game->player2.playerPos.x/* + PLAYER_WIDTH*/, game->player2.playerPos.y + PLAYER_HEIGHT)});

    if (isCollisionP1 || isCollisionP2)
        game->ball.ballDir.x *= - 1;
}

void ball_collision(game_t* game)
{
    if (game->ball.ballPos.y - BALL_RADIUS <= 0)
        game->ball.ballDir.y *= -1;
    if (game->ball.ballPos.y + BALL_RADIUS >= game->height)
        game->ball.ballDir.y *= -1;

    if (game->ball.ballPos.x <= 0.f)
        reset_game(game);
    if (game->ball.ballPos.x + BALL_RADIUS * 2.f >= game->width)
        reset_game(game);
}

void move_ball(game_t* game, const game_inputs_t* inputs)
{
    game->ball.ballPos = addition_vectors(game->ball.ballPos, game->ball.ballDir);
}
