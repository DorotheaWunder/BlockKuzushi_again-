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
        if (isGameLost || isGameWon) {
            BeginDrawing();

            if (isGameLost) {
                DisplayGameLost();
            } else if (isGameWon) {
                DisplayGameWon();
            }

            EndDrawing();

            if (IsKeyPressed(KEY_Q)) {
                break;  // Quit the game
            }
            if (IsKeyPressed(KEY_R)) {
                ResetGame(&game);  // Reset and start a new game
                continue;  // Restart the loop for the new game
            }

            continue;  // Prevent rendering the game visuals
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