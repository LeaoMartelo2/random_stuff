#include <raylib.h>
#include <stdbool.h>

#define MAX_FPS 100
#define WIDTH 800
#define HEIGHT 600
#define SIZE 100
#define SPEED 10

#define TEXT "hi"

int main() {

    /*SetConfigFlags(FLAG_WINDOW_RESIZABLE);*/
    /*MaximizeWindow();*/
    InitWindow(WIDTH, HEIGHT, "Raylib");
    /*SetTargetFPS(MAX_FPS);*/

    Rectangle square = {
        .x = (float)WIDTH / 2,
        .y = (float)HEIGHT / 2,
        .width = 100,
        .height = 100,
    };

    while (!WindowShouldClose()) {

        ClearBackground(BLANK);

        float deltaTime = GetFrameTime();
        DrawFPS(1, 1);

        BeginDrawing();

        {
            if (IsKeyDown(KEY_A)) {
                if (square.width - 10 > 0) {
                    square.width = square.width - 1000 * deltaTime;
                    square.height = square.height - 1000 * deltaTime;
                }
            }

            if (IsKeyDown(KEY_D)) {
                if (square.height + 10 < 500) {
                    square.width = square.width + 1000 * deltaTime;
                    square.height = square.height + 1000 * deltaTime;
                }
            }

            DrawRectangle(square.x, square.y, square.width, square.height, GREEN);
            DrawText(TEXT, square.x + (square.width / 2) - 1, square.y + square.height / 2, 20, WHITE);
            Vector2 mouse_pos = GetMousePosition();

            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
                /*printf("mouse: {x:%f, y:%f} \n", mouse_pos.x, mouse_pos.y);*/

                if (CheckCollisionPointRec(mouse_pos, square)) {
                    /*printf("is inside square!\n");*/
                    square.x = mouse_pos.x - square.width / 2;
                    square.y = mouse_pos.y - square.height / 2;
                }
            }
        }
        EndDrawing();
    }
    return 0;
}
