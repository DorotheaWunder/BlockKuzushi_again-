#include "raylib.h"

#include "screenvalues.h"

ScreenSetup InitializeScreen()
{
    return (ScreenSetup)
    {
        1000,
        600,
        BLACK,
        "Block Kuzushi"
    };
}