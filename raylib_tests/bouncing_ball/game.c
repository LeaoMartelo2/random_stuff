#include <raylib.h>
#include <stdbool.h>

#define MAX_FPS 60
#define WIDTH 800
#define HEIGHT 600
#define SIZE 30
#define SPEED 10

int main() {

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    MaximizeWindow();
    InitWindow(GetScreenWidth(), GetScreenHeight(), "Bouncing ball");
    SetTargetFPS(MAX_FPS);

    /*start ball in the middle of the screen*/
    int x = WIDTH / 2;
    int y = HEIGHT / 2;

    int radius = SIZE / 2;
    int speed_x = SPEED;
    int speed_y = SPEED;

    int rect_x = WIDTH / 1;
    int rect_y = HEIGHT / 1;

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
                /*radius++;*/

                /*ClearBackground(BLACK);*/
            }
            x = x + speed_x;
            y = y + speed_y;

            /*DrawCircle(x, y, radius, WHITE);*/

            DrawRectangle(rect_x, rect_y, SIZE * 2, SIZE * 2, GREEN);
            Vector2 mouse_pos = GetMousePosition();

            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
                rect_x = mouse_pos.x;
                rect_y = mouse_pos.y;
            }
        }
        EndDrawing();
    }
    return 0;
}
