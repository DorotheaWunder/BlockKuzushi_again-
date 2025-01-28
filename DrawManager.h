#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include "cmake-build-debug/_deps/raylib-src/src/raylib.h"
#include "screenvalues.h"
#include "paddlevalues.h"
#include "ballvalues.h"
#include "gridvalues.h"
#include "upgrade.h"

void DrawGameVisuals(Paddle *player, Ball *ball, Upgrade *upgrade);


#endif //DRAWMANAGER_H