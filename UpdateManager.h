#ifndef UPDATEMANAGER_H
#define UPDATEMANAGER_H

#include "ballvalues.h"
#include "paddlevalues.h"
#include "blockvalues.h"
#include "gridvalues.h"
#include "upgrade.h"

void UpdatePaddle(Paddle *player);
void UpdateBall(Ball *ball, Paddle *player);
void CheckCollisions(Ball *ball, Paddle *player);
void UpdateGridBlocks();
void UpdateUpgrades(Upgrade *upgrade, Paddle *player, Ball *ball);

void UpdateGame(Paddle *player, Ball *ball, Upgrade *upgrade);

#endif //UPDATEMANAGER_H