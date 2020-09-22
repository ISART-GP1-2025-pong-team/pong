#pragma once

#include <stdbool.h>

typedef struct game_t game_t;

float random_float(float min, float max);

// Player should stay inside the screen
void move_player(game_t* game, const game_inputs_t* inputs);
//bool point_inside_rect(float x, float y, float y2, float rx, float ry, float rw, float rh);

void ball_collision(game_t* game);
void ball_collision_player(game_t* game);
void reset_ball(game_t* game);
void move_ball(game_t* game, const game_inputs_t* inputs);

// Check if the player is hit by a bullet using bullet position and PLAYER_WIDTH/PLAYER_HEIGHT
//bool player_is_hit_by_bullet(player_t* player, bullet_t* bullet);
