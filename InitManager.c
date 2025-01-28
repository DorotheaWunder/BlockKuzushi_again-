#include "initmanager.h"

GameElements InitializeGame()
{
    ScreenSetup screen = InitializeScreen();
    InitWindow(screen.screen_Width, screen.screen_Height, screen.game_Title);

    Paddle player = InitializePaddleValues();

    Ball ball = InitializeBallValues();

    InitializeGridValues();

    Upgrade upgrade = InitializeUpgradeValues();

    return (GameElements)
    {
        .screen = screen,
        .player = player,
        .ball = ball,
        .upgrade = upgrade
    };
}