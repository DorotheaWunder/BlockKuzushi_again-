#include "raylib.h"
#include "raymath.h"
#include "upgrade.h"
#include "paddlevalues.h"
#include "ballvalues.h"
#include "blockvalues.h"

Upgrade InitializeUpgradeValues()
{
    return (Upgrade)
    {
        .size = 10.0f,
        .velocity = (Vector2){ 0.0f, 100.0f },

        .rotation_Angle = 0.0f,
        .rotation_Speed = 100.0f,

        .type = BALL_NUMBER,
        .is_Active = 0,

        .main_Color = GOLD,
        .outline_Color = YELLOW,
        .outline_Thickness = 0.2f
    };
}

void CalculateTriangle(Upgrade *upgrade)
{
    Vector2 center = upgrade->position;

    upgrade->point1 = (Vector2){ center.x, center.y - upgrade->size  };
    upgrade->point2 = (Vector2){ center.x - upgrade->size, center.y + upgrade->size };
    upgrade->point3 = (Vector2){ center.x + upgrade->size, center.y + upgrade->size };
}

void DrawUpgradeVisuals(Upgrade *upgrade)
{
    if (upgrade->is_Active)
    {
        CalculateTriangle(upgrade);

        DrawTriangle(upgrade->point1, upgrade->point2, upgrade->point3, upgrade->main_Color);
        DrawTriangleLines(upgrade->point1, upgrade->point2, upgrade->point3, upgrade->outline_Color);
    }
}

void IncreasePaddleSize(Paddle *paddle)
{
    paddle->visuals.paddle.width += 50;
    //add cap to size (maybe in paddle values?)
}

void IncreaseBallNumber(Ball *ball)
{
    if (activeBalls < BALLS_MAX)
    {
        Ball *newBall = &balls[activeBalls];
        *newBall = *ball;

        newBall->position.ball_Position.x += 10 * activeBalls;
        newBall->physics.ball_Velocity = Vector2Rotate(ball->physics.ball_Velocity, DEG2RAD * (10 * activeBalls));

        activeBalls++;
    }
}

void IncreaseBallStrength(Ball *ball)
{

}

bool PointInsideRect(Vector2 point, Rectangle rect)
{
    return (point.x >= rect.x && point.x <= (rect.x + rect.width) &&
            point.y >= rect.y && point.y <= (rect.y + rect.height));
}

bool UpgradeHitsPaddle(Upgrade *upgrade, Paddle *paddle)
{
    CalculateTriangle(upgrade);

    Rectangle paddleRect = CalculatePaddleSize(paddle);

    return PointInsideRect(upgrade->point1, paddleRect) ||
           PointInsideRect(upgrade->point2, paddleRect) ||
           PointInsideRect(upgrade->point3, paddleRect);
}

void SpawnUpgrade(Upgrade *upgrade)
{
    float screen_Padding = 15.0f;
    float randomX = GetRandomValue(screen_Padding, GetScreenWidth() - screen_Padding);

    upgrade->position = (Vector2){ randomX, 0.0f };
    upgrade->type = GetRandomValue(1, 1);
    upgrade->is_Active = 1;
}

void DeactivateUpgrade(Upgrade *upgrade, Paddle *paddle, Ball *ball)
{
    if (upgrade->position.y > GetScreenHeight() -5)
    {
        upgrade->is_Active = 0;
    }
    else if (UpgradeHitsPaddle(upgrade, paddle))
    {
        if (upgrade->type == PADDLE_SIZE)
        {
            IncreasePaddleSize(paddle);
        }
        else if (upgrade->type == BALL_NUMBER)
        {
            IncreaseBallNumber(ball);
        }

        upgrade->is_Active = 0;
    }
}