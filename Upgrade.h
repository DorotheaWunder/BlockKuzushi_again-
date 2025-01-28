#ifndef UPGRADE_H
#define UPGRADE_H

#include "raylib.h"
#include "paddlevalues.h"
#include "ballvalues.h"

typedef enum {
    NONE = 0,
    PADDLE_SIZE,
    BALL_NUMBER,
    BALL_STRENGTH
} UpgradeType;

typedef struct
{
    float size;
    Vector2 position;
    Vector2 velocity;

    float rotation_Angle;
    float rotation_Speed;

    UpgradeType type;
    int is_Active;

    Color main_Color;
    Color outline_Color;
    float outline_Thickness;

    Vector2 point1;
    Vector2 point2;
    Vector2 point3;
} Upgrade;


Upgrade InitializeUpgradeValues();
void DrawUpgradeVisuals(Upgrade *upgrade);
void SpawnUpgrade(Upgrade *upgrade);
void DeactivateUpgrade(Upgrade *upgrade, Paddle *paddle, Ball *ball);
//void UpdateUpgradePosition(Upgrade *upgrade, float deltaTime);

#endif //UPGRADE_H
