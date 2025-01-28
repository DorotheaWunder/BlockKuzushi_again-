#ifndef BALLVALUES_H
#define BALLVALUES_H

#include "raylib.h"

#include "blockvalues.h"
#include "paddlevalues.h"


#define BALLS_MAX 10

typedef struct
{
    float ball_Radius;
    Color ball_Color;
} BallVisuals;

typedef struct
{
    int player_Lives;
    int is_Active;
} BallHealth;

typedef struct
{
    float ball_Speed;
    Vector2 ball_Velocity;
} BallPhysics;

typedef struct
{
    Vector2 ball_Position;
} BallPosition;

typedef struct
{
    int isColliding;
} BallCollision;

typedef struct
{
    BallVisuals visuals;
    BallHealth health;
    BallPhysics physics;
    BallPosition position;
    BallCollision collision;
    //has strength upgrade
} Ball;

extern Ball balls[BALLS_MAX];
extern int activeBalls;


Ball InitializeBallValues();
void DrawBallVisuals(BallVisuals visuals, BallPosition position);
void BallDeathRespawn(Ball *ball);

void UpdateBallPosition(Ball *ball);
void InvertBallMovement(Ball *ball, char axis);

void CollisionBallScreen(Ball *ball);
void CollisionBallPaddle(Ball *ball, Paddle *player);
void CollisionBallBlock(Ball *ball, Block *block);



#endif //BALLVALUES_H