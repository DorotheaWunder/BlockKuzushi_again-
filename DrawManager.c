#include "raylib.h"
#include "drawmanager.h"

void DrawGameVisuals(Paddle *player, Ball *ball, Upgrade *upgrade)
{
    DrawRectangleRec(player->visuals.paddle, player->visuals.color);

    DrawBallVisuals(ball->visuals, ball->position);

    DrawGridVisuals();

    DrawUpgradeVisuals(upgrade);
}