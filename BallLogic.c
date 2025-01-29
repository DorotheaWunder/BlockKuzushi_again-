#include "raylib.h"
#include "raymath.h"

#include "ballvalues.h"
#include "gameflow.h"

Ball balls[BALLS_MAX];
int activeBalls = 10;

Ball InitializeBallValues()
{
    return (Ball)
    {
        .visuals =
        {
            .ball_Radius = 5.0f,
            .ball_Color = WHITE,
            },
        .health =
        {
            .player_Lives = 10,
            .is_Active = 1,
            },
        .physics =
        {
            .ball_Speed = 5.0f,
            .ball_Velocity = (Vector2){1.0f, -1.0f},
            },
        .position =
        {
            .ball_Position = (Vector2){450.0f, 500.0f},
            },
        .collision =
        {
            .isColliding = 0,
            }
    };
}

void DrawBallVisuals(BallVisuals visuals, BallPosition position)
{
    DrawCircleV(position.ball_Position, visuals.ball_Radius, visuals.ball_Color);
}

void BallDeathRespawn(Ball *ball)
{
    if (ball->position.ball_Position.y > GetScreenHeight())
    {
        ball->health.is_Active = 0;

        if (ball->health.player_Lives > 0)
        {
            activeBalls = 1;
            ball->health.player_Lives--;
            ball->health.is_Active = 1;
            ball->position.ball_Position = (Vector2){450.0f, 500.0f};
            ball->physics.ball_Velocity = (Vector2){1.0f, -1.0f};
        }
        else
        {
            isGameLost = 1;
        }
    }
}