#ifndef __GAME_H__
#define __GAME_H__

#include <stdbool.h>
#include "vector2.h"

#define M_PI       3.14159265358979323846

// Game constants
const int   SCREEN_PADDING;      // px
const float PLAYER_SPEED;        // px/s
const int   PLAYER_WIDTH;        // px
const int   PLAYER_HEIGHT;       // px
const int   BALL_WIDTH;          // px
const int   BALL_HEIGHT;         // px
const float BALL_RADIUS;
const float BALL_SPEED;
//const float M_PI;

typedef enum game_buttons_e
{
    BUTTON_UP,
    BUTTON_DOWN,
    BUTTON_W,
    BUTTON_S,
    BUTTON_SPACE,

    BUTTON_COUNT
} game_buttons_e;

typedef struct game_inputs_t
{
    bool buttons[BUTTON_COUNT];
    float deltaTime;

} game_inputs_t;

typedef struct player_t
{
    vector2_t playerPos;
} player_t;

typedef struct ball_t
{
    vector2_t ballPos;
    vector2_t ballDir;

    float angle;
    float isLeft;
} ball_t;

typedef struct game_t
{
    // Size in pixels
    int width;
    int height;

    vector2_t i;
    vector2_t j;

    player_t player1;
    player_t player2;

    ball_t ball;

    bool isGameStart;

} game_t;

void game_init(game_t* game, int width, int height);
void game_destroy(game_t* game);

void game_update(game_t* game, const game_inputs_t* inputs);

#endif