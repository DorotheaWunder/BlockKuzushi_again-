#include "raylib.h"
#include "gameflow.h"
#include "updatemanager.h"
#include "initmanager.h"
#include "drawmanager.h"
#include "blockvalues.h"
#include "paddlevalues.h"

Paddle player;
Ball ball;
Upgrade upgrade;

int isGameLost = 0;
int isGameWon = 0;

bool AllBlocksDestroyed()
{
    for (int row = 0; row < ROW; row++)
    {
        for (int col = 0; col < COL; col++)
        {
            if (blockGrid[row][col].block_Health > 0)
            {
                return false;
            }
        }
    }
    return true;
}

bool AllLivesLost()
{
    return balls->health.player_Lives <= 0;
}

void DisplayGameLost()
{
    ClearBackground(BLACK);
    DrawText("GAME OVER", 300, 250, 60, RED);
    DrawText("Press 'Q' to quit or 'R' to replay", 300, 350, 20, WHITE);
}

void DisplayGameWon()
{
    ClearBackground(BLACK);
    DrawText("YOU WIN", 300, 250, 60, GREEN);
    DrawText("Press 'Q' to quit or 'R' to replay", 300, 350, 20, WHITE);
}

void GameLoop()
{
    if (isGameLost) {
        DisplayGameLost();
        return;
    }
    if (isGameWon) {
        DisplayGameWon();
        return;
    }

    UpdateGame(&player, &ball, &upgrade);

    DrawGameVisuals(&player, &ball, &upgrade);
}

void ResetGame(GameElements *game)
{
    *game = InitializeGame();

    isGameLost = 0;
    isGameWon = 0;
}

