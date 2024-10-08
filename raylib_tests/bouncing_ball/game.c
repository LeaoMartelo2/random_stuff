#include <raylib.h>
#include <stdbool.h>

#define MAX_FPS 60
#define WIDTH 800
#define HEIGHT 600
#define SIZE 50
#define SPEED 10

int main() {

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    /*MaximizeWindow();*/
    InitWindow(WIDTH, HEIGHT, "Raylib");
    SetTargetFPS(MAX_FPS);

    /*start ball in the middle of the screen*/
    int x = WIDTH / 2;
    int y = HEIGHT / 2;

    int radius = SIZE / 2;
    int speed_x = SPEED;
    int speed_y = SPEED;

    while (!WindowShouldClose()) {

        ClearBackground(BLACK);

        float deltaTime = GetFrameTime();
        DrawFPS(1, 1);

        bool hit_sides = false;
        bool hit_up_down = false;

        BeginDrawing();

        {
            if (x - radius <= 0 || x + radius >= GetScreenWidth()) {
                speed_x = -1 * speed_x;
                x = x + speed_x;
                hit_sides = true;
            }

            if (y - radius <= 0 || y + radius >= GetScreenHeight()) {
                speed_y = -1 * speed_y;
                y = y + speed_y;
                hit_up_down = true;
            }

            if (hit_sides || hit_up_down) {
                radius = radius + 10;

                // ClearBackground(BLACK);
            }
            x = x + speed_x;
            y = y + speed_y;

            DrawCircle(x, y, radius, WHITE);
        }
        EndDrawing();
    }
    return 0;
}
