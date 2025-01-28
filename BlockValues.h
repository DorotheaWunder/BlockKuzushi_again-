#ifndef BLOCKVALUES_H
#define BLOCKVALUES_H

#include "raylib.h"

typedef enum
{
    DESTROYED = 0,
    VERY_LOW = 1,
    LOW = 2,
    MEDIUM = 3,
    HIGH = 4,
    VERY_HIGH = 5
} BlockHealth;

extern Color health_colors[];

typedef struct
{
    int block_Width;
    int block_Height;
    BlockHealth block_Health;

    int row_Position;
    int col_Position;
    float x_Coord;
    float y_Coord;

    Color block_Color;
    Color outline_Color;
    int outline_Thickness;
} Block;


Block InitializeBlockValues(int width, int height, int health, int row, int col);
void DrawBlockVisuals(Block *block);
void UpdateBlock(Block *block);

#endif //BLOCKVALUES_H
