
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <gp/gp.h>

#include "game.h"

const int   WIDTH  = 400;
const int   HEIGHT = 200;
const int   SCALE  = 4;
const char* TITLE  = "pong";

void render_player(GPLib* gp, const player_t* player)
{
    gpDrawRectFilled(gp, (GPRect){player->playerPos.x, HEIGHT - player->playerPos.y, PLAYER_WIDTH, PLAYER_HEIGHT}, GP_CBLACK);
}

void render_ball(GPLib* gp, const ball_t* ball)
{
    gpDrawCircleFilled(gp, (GPVector2){ball->ballPos.x, HEIGHT - ball->ballPos.y}, BALL_RADIUS, GP_CBLACK);
}
/*
void render_ball(GPLib* gp, const ball_t* ball)
{
     gpDrawCircleFilled(gp, (GPVector2){player->x, player->y}, 4.f, GP_CBLACK);
}*/

void game_render(GPLib* gp, const game_t* game)
{
    {
        const player_t* player1 = &game->player1;
        render_player(gp, player1);
        
        const player_t* player2 = &game->player2;
        render_player(gp, player2);
    }
    
    const ball_t* ball = &game->ball;
    render_ball(gp, ball); 
}

int main(int argc, char* argv[])
{
    // Init system
    GPLib* gp = gpInit(WIDTH * SCALE, HEIGHT * SCALE, TITLE, GP_VSYNC_ON);
    if (gp == NULL)
    {
        fprintf(stderr, "Cannot init gplib\n");
        return 1;
    }

    // Create intermediate framebuffer with lower resolution
    GPFramebuffer screen = gpFramebufferLoad(gp, WIDTH, HEIGHT);

    game_t game;
    game_init(&game, WIDTH, HEIGHT);

    int buttonMapping[BUTTON_COUNT] = {
        GP_KEY_UP,
        GP_KEY_DOWN,
        GP_KEY_W,
        GP_KEY_S,
        GP_KEY_SPACE,
    };

    // Main loop
    while (!gpWindowShouldClose(gp))
    {
        gpEventsPoll(gp);

        // Update game
        game_inputs_t inputs = {};
        for (int i = 0;i < BUTTON_COUNT; ++i)
        {
            inputs.buttons[i] = gpKeyIsDown(gp, buttonMapping[i]);
        }
        inputs.deltaTime = gpGetFrameTime(gp);

        game_update(&game, &inputs);

        // Render game
        gpDrawBegin(gp);
        gpFramebufferDrawBegin(gp, screen);
        gpDrawClearBackground(gp, (GPColor){0.8f, 0.8f, 0.8f, 1.f});

        // Draw here!
        game_render(gp, &game);
        
        gpFramebufferDrawEnd(gp);

        gpDrawTextureEx2(gp, screen.texture, (GPRect){0.f, 0.f, WIDTH, HEIGHT}, (GPRect){ 0.f, 0.f, WIDTH*SCALE, HEIGHT*SCALE }, GP_CWHITE);
        gpDrawEnd(gp);
    }

    game_destroy(&game);

    // Shutdown system
    gpShutdown(gp);
    return 0;
}

