#include "raylib.h"
#include "raymath.h"

#include "screenvalues.h"
#include "paddlevalues.h"
#include "ballvalues.h"

void UpdateBallPosition(Ball *ball)
{
    ball->position.ball_Position.x += ball->physics.ball_Velocity.x * ball->physics.ball_Speed;
    ball->position.ball_Position.y += ball->physics.ball_Velocity.y * ball->physics.ball_Speed;
}

void InvertBallMovement(Ball *ball, char axis)
{
    if (axis == 'x')
    {
        ball->physics.ball_Velocity.x *= -1;
    }
    else if (axis == 'y')
    {
        ball->physics.ball_Velocity.y *= -1;
    }
}