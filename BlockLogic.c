﻿#include "raylib.h"
#include "raymath.h"

#include "blockvalues.h"

Color health_colors[] = {
    BLANK,
    (Color){ 2, 125, 67, 255 },
    (Color){ 3, 175, 93, 255 },
    (Color){ 4, 226, 120, 255 },
    (Color){ 29, 251, 146, 255 },
    (Color){ 80, 252, 170, 255 }
};

Block InitializeBlockValues(int width, int height, int health, int row, int col)
{
    return (Block)
    {
        .block_Width = width,
        .block_Height = height,
        .block_Health = health,

        .row_Position = row,
        .col_Position = col,
        .x_Coord = col * width,
        .y_Coord = row * height,

        .block_Color = health_colors[health],
        .outline_Color = BLACK,
        .outline_Thickness = 2
    };
}

void DrawBlockVisuals(Block *block)
{
    if (block->block_Health != DESTROYED)
    {
        DrawRectangle(
            block->x_Coord, block->y_Coord,
            block->block_Width, block->block_Height,
            block->block_Color
        );

        DrawRectangleLinesEx(
            (Rectangle)
            {
                block->x_Coord, block->y_Coord,
                block->block_Width, block->block_Height
            },
            block->outline_Thickness,
            block->outline_Color
        );
    }
}

void UpdateBlock(Block *block)
{
    if (block->block_Health <= 0)
    {
        block->block_Health = DESTROYED;
        block->block_Color = BLANK;
    }
    else
    {
        block->block_Color = health_colors[block->block_Health];
    }
}
