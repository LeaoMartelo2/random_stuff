#include <raylib.h>
#include <stdbool.h>

int main() {

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "Bouncing ball");
    SetTargetFPS(60);

    int x = 250;
    int y = 250;
    int radius = 50;
    int speedX = 5;
    int speedY = 5;

    while (!WindowShouldClose()) {

        float deltaTime = GetFrameTime();

        bool H_X = false;
        bool H_Y = false;

        BeginDrawing();
        ClearBackground(BLACK);
        {
            if (x - radius <= 0 || x + radius >= GetScreenWidth()) {
                speedX = -1 * speedX;
                x = x + speedX;
                H_X = true;
            }

            if (y - radius <= 0 || y + radius >= GetScreenHeight()) {
                speedY = -1 * speedY;
                y = y + speedY;
                H_Y = true;
            }

            if (H_X || H_Y) {
                /*r++;*/
            }
            x = x + speedX;
            y = y + speedY;

            DrawCircle(x, y, radius, GREEN);
        }
        EndDrawing();
    }
    return 0;
}
