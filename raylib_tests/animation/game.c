#include "raylib.h"
#include <math.h>

#define WIDTH 980
#define HEIGHT 650

int main(void) {
    InitWindow(WIDTH, HEIGHT, "Test");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        /*ClearBackground(BLACK);*/

        float w = GetScreenWidth();
        float h = GetScreenHeight();
        float delta_time = GetFrameTime();
        float t = GetTime();

        float rect_width = 20.0f;
        float rect_height = 20.0f;

        BeginDrawing();
        {
            DrawRectangle((w - rect_width) * (sinf(t * 2.0f) + 1.0f) * 0.5f, /* x pos */
                          h / 2 - rect_height / 2,                           /* y pos */
                          rect_width, rect_height,                           /* size  */
                          RED);                                              /* color */
        }
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
