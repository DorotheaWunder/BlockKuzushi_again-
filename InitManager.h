#ifndef INITMANAGER_H
#define INITMANAGER_H

#include "screenvalues.h"
#include "paddlevalues.h"
#include "ballvalues.h"
#include "gridvalues.h"
#include "blockvalues.h"
#include "upgrade.h"

typedef struct
{
    ScreenSetup screen;
    Paddle player;
    Ball ball;
    Upgrade upgrade;
} GameElements;

GameElements InitializeGame();
#endif //INITMANAGER_H