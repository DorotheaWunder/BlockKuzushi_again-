#include "raylib.h"
#include "raymath.h"

#include "screenvalues.h"
#include "paddlevalues.h"
#include "ballvalues.h"
#include "blockvalues.h"
#include "gridvalues.h"
#include "upgrade.h"

#include "initmanager.h"
#include "updatemanager.h"
#include "drawmanager.h"

#include "gameflow.h"



int main()
{
    GameElements game = InitializeGame();

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if (isGameLost) {
            DisplayGameLost();
            return 0;
        }
        if (isGameWon) {
            DisplayGameWon();
            return 0;
        }

        UpdateGame(&game.player, &game.ball, &game.upgrade);

        BeginDrawing();

        ClearBackground(game.screen.color_Background);

        DrawGameVisuals(&game.player, &game.ball, &game.upgrade);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}