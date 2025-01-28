#ifndef GAMEFLOW_H
#define GAMEFLOW_H

#include "blockvalues.h"
#include "ballvalues.h"
#include "gridvalues.h"
#include "upgrade.h"

extern Paddle player;
extern Ball ball;
extern Upgrade upgrade;

extern int isGameLost;
extern int isGameWon;

bool AllBlocksDestroyed();
bool AllLivesLost();

void DisplayGameLost();
void DisplayGameWon();

void GameLoop();


#endif //GAMEFLOW_H
