#include "paddlevalues.h"

Paddle InitializePaddleValues()
{
    return (Paddle) {
        .visuals = {
            .paddle = {400, 550, 100, 20},
            .color = WHITE
        },
        .values = {
            .movement_speed = 7.0f
        },
        .controls = {
            .key_Left = {KEY_A, KEY_LEFT},
            .key_Right = {KEY_D, KEY_RIGHT}
        }
    };
}

Rectangle CalculatePaddleSize(Paddle *paddle)
{
    return paddle->visuals.paddle;
}

void HandlePlayerInput(Paddle *player)
{
    if (IsKeyDown(player->controls.key_Left[0]) || IsKeyDown(player->controls.key_Left[1])) {
        player->visuals.paddle.x -= player->values.movement_speed;
    }
    if (IsKeyDown(player->controls.key_Right[0]) || IsKeyDown(player->controls.key_Right[1])) {
        player->visuals.paddle.x += player->values.movement_speed;
    }
}

void ScreenBoundsPaddle(Paddle *player)
{
    if (player->visuals.paddle.x < 0) {
        player->visuals.paddle.x = 0;
    }
    if (player->visuals.paddle.x + player->visuals.paddle.width > GetScreenWidth()) {
        player->visuals.paddle.x = GetScreenWidth() - player->visuals.paddle.width;
    }
}

void UpdatePaddleMovement(Paddle *player)
{
    HandlePlayerInput(player);
    ScreenBoundsPaddle(player);
}