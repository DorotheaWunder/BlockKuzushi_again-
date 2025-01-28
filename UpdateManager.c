#include "updatemanager.h"

void UpdatePaddle(Paddle *player)
{
    UpdatePaddleMovement(player);
}

void UpdateBall(Ball *ball, Paddle *player)
{
    UpdateBallPosition(ball);
    CollisionBallScreen(ball);
    BallDeathRespawn(ball);

    CheckCollisions(ball, player);
}

void CheckCollisions(Ball *ball, Paddle *player)
{
    CollisionBallPaddle(ball, player);

    for (int row = 0; row < ROW; row++)
    {
        for (int col = 0; col < COL; col++)
        {
            Block *block = &blockGrid[row][col];
            if (block->block_Health > 0)
            {
                CollisionBallBlock(ball, block);
            }
        }
    }
}

void UpdateGridBlocks()
{
    for (int row = 0; row < ROW; row++)
    {
        for (int col = 0; col < COL; col++)
        {
            Block *block = &blockGrid[row][col];
            if (block->block_Health > 0)
            {
                UpdateBlock(block);
            }
        }
    }
}

void UpdateUpgrades(Upgrade *upgrade, Paddle *paddle, Ball *ball)
{
    if (!upgrade->is_Active)
    {
        SpawnUpgrade(upgrade);
    }

    if (upgrade->is_Active)
    {
        upgrade->position.y += upgrade->velocity.y * GetFrameTime();
        DeactivateUpgrade(upgrade, paddle, ball);


        // if (upgrade->position.y > GetScreenHeight())
        // {
        //     DeactivateUpgrade(upgrade, paddle);
        // }
    }
}


void UpdateGame(Paddle *player, Ball *ball, Upgrade *upgrade)
{
    UpdatePaddle(player);

    UpdateBall(ball, player);

    UpdateGridBlocks();

    UpdateUpgrades(upgrade, player, ball);
}