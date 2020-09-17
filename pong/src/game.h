#pragma once

#include <stdbool.h>

// Game constants
const int   SCREEN_PADDING;      // px
const float PLAYER_SPEED;        // px/s
const int   PLAYER_WIDTH;        // px
const int   PLAYER_HEIGHT;       // px
const int   BALL_WIDTH;         // px
const int   BALL_HEIGHT;        // px
const float BALL_RADIUS;

typedef enum game_buttons_e
{
    BUTTON_UP,
    BUTTON_DOWN,
    BUTTON_W,
    BUTTON_S,

    BUTTON_COUNT
} game_buttons_e;

typedef struct game_inputs_t
{
    bool buttons[BUTTON_COUNT];
    float deltaTime;

} game_inputs_t;

typedef struct player_t
{
    float x;
    float y;
} player_t;

typedef struct ball_t
{
    float x;
    float y;
    float xSpeed;
    float ySpeed;
    bool isLeft;
} ball_t;

typedef struct game_t
{
    // Size in pixels
    int width;
    int height;

    player_t player1;
    player_t player2;

    ball_t ball;

    int ballDirection; // -1: left, +1: right
} game_t;

void game_init(game_t* game, int width, int height);
void game_destroy(game_t* game);

void game_update(game_t* game, const game_inputs_t* inputs);

