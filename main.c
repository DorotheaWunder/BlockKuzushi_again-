#include "raylib.h"
#include "raymath.h"

#include "screenvalues.h"
#include "paddlevalues.h"
#include "ballvalues.h"
#include "blockvalues.h"
#include "gridvalues.h"

#include "initmanager.h"
#include "updatemanager.h"
#include "drawmanager.h"

#include "upgrade.h"

int main()
{
    GameElements game = InitializeGame();

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateGame(&game.player, &game.ball, &game.upgrade);

        BeginDrawing();
        ClearBackground(game.screen.color_Background);

        DrawGameVisuals(&game.player, &game.ball, &game.upgrade);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}