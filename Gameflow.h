#ifndef GAMEFLOW_H
#define GAMEFLOW_H

#include "blockvalues.h"
#include "ballvalues.h"
#include "gridvalues.h"
#include "upgrade.h"
#include "initmanager.h"

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
void ResetGame(GameElements *game);


#endif //GAMEFLOW_H
