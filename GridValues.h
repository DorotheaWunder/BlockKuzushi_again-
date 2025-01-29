#ifndef GRIDVALUES_H
#define GRIDVALUES_H

#include "blockvalues.h"

#define ROW 10
#define COL 10

extern Block blockGrid[ROW][COL];

void InitializeGridValues();
void DrawGridVisuals();
void UpdateGrid(Ball *ball);

#endif //GRIDVALUES_H

