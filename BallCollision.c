#include "raylib.h"
#include "raymath.h"

#include "screenvalues.h"
#include "paddlevalues.h"
#include "ballvalues.h"
#include "blockvalues.h"

#define ROW 13
#define COL 10

int BoundsCollision(Ball *ball)
{
    return (ball->position.ball_Position.x - ball->visuals.ball_Radius < 0 ||
            ball->position.ball_Position.x + ball->visuals.ball_Radius > GetScreenWidth() ||
            ball->position.ball_Position.y - ball->visuals.ball_Radius < 0 ||
            ball->position.ball_Position.y + ball->visuals.ball_Radius > GetScreenHeight());
}

void CollisionBallScreen(Ball *ball)
{
    if (ball->position.ball_Position.x - ball->visuals.ball_Radius <= 0 ||
        ball->position.ball_Position.x + ball->visuals.ball_Radius >= GetScreenWidth())
    {
        InvertBallMovement(ball, 'x');
    }
    if (ball->position.ball_Position.y - ball->visuals.ball_Radius <= 0)
    {
        InvertBallMovement(ball, 'y');
    }
}

bool BallHitsRectangle(Ball *ball, Rectangle rectangle)
{
    int ballLeft = ball->position.ball_Position.x - ball->visuals.ball_Radius;
    int ballRight = ball->position.ball_Position.x + ball->visuals.ball_Radius;
    int ballTop = ball->position.ball_Position.y - ball->visuals.ball_Radius;
    int ballBottom = ball->position.ball_Position.y + ball->visuals.ball_Radius;

    int rectLeft = rectangle.x;
    int rectRight = rectangle.x + rectangle.width;
    int rectTop = rectangle.y;
    int rectBottom = rectangle.y + rectangle.height;

    return !(ballRight < rectLeft || ballLeft > rectRight || ballBottom < rectTop || ballTop > rectBottom);
}

void CollisionBallPaddle(Ball *ball, Paddle *paddle)
{
    Rectangle paddleRect = paddle->visuals.paddle;

    if (BallHitsRectangle(ball, paddleRect))
    {
        InvertBallMovement(ball, 'y');
    }
}

void CollisionBallBlock(Ball *ball, Block *block)
{
    if (block->block_Health > 0)
    {
        Rectangle blockRect = {
            block->x_Coord,
            block->y_Coord,
            block->block_Width,
            block->block_Height
        };

        if (BallHitsRectangle(ball, blockRect))
        {
            float ballCenterX = ball->position.ball_Position.x;
            float ballCenterY = ball->position.ball_Position.y;

            if (ballCenterX < block->x_Coord || ballCenterX > block->x_Coord + block->block_Width)
            {
                InvertBallMovement(ball, 'x');
            }
            else if (ballCenterY < block->y_Coord || ballCenterY > block->y_Coord + block->block_Height)
            {
                InvertBallMovement(ball, 'y');
            }

            block->block_Health--;
            UpdateBlock(block);
        }
    }
}