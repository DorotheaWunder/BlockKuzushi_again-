#ifndef PADDLEVALUES_H
#define PADDLEVALUES_H

#include "raylib.h"


typedef struct {
    Rectangle paddle;
    Color color;
} PaddleVisuals;

typedef struct {
    float movement_speed;
} PaddleValues;

typedef struct {
    int key_Left[2];
    int key_Right[2];
} PlayerControls;

typedef struct
{
    PaddleVisuals visuals;
    PaddleValues values;
    PlayerControls controls;
} Paddle;


Paddle InitializePaddleValues();
Rectangle CalculatePaddleSize(Paddle *paddle);
void HandlePlayerInput(Paddle *player);
void UpdatePaddleMovement(Paddle *player);
void ScreenBoundsPaddle(Paddle *player);

#endif