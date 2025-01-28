#ifndef SCREENVALUES_H
#define SCREENVALUES_H

#include "raylib.h"

typedef struct ScreenSetup
{
    int screen_Width;
    int screen_Height;
    Color color_Background;
    const char *game_Title;
} ScreenSetup;

ScreenSetup InitializeScreen();

#endif //SCREENVALUES_H