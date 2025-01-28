#include "raylib.h"
#include "raymath.h"

#include "ballvalues.h"
#include "blockvalues.h"
#include "gridvalues.h"

Block blockGrid[ROW][COL];

void InitializeGridValues()
{
    for (int row = 0; row < ROW; row++)
    {
        for (int col = 0; col < COL; col++)
        {
            int health = GetRandomValue(DESTROYED, VERY_LOW);
            //int health = GetRandomValue(VERY_LOW, VERY_HIGH);
            blockGrid[row][col] = InitializeBlockValues(100, 30, health, row, col);
        }
    }
}

void DrawGridVisuals()
{
    for (int row = 0; row < ROW; row++)
    {
        for (int col = 0; col < COL; col++)
        {
            Block *block = &blockGrid[row][col];

            DrawBlockVisuals(block);
        }
    }
}