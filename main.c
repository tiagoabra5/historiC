#include "raylib.h"
#include "types.h"
#include "game.h"
#include "renderer.h"

int main(void)
{
    InitWindow(SCREEN_W, SCREEN_H, "historiC - Um quiz sobre a historia da computacao");
    SetTargetFPS(60);

    Game g;
    GameInit(&g);

    while (!WindowShouldClose()) {
        GameUpdate(&g);
        Render(&g);
    }

    CloseWindow();
    return 0;
}
