#include <raylib.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_FPS 100
#define WIDTH 600
#define HEIGHT 600
#define SIZE 100
#define SPEED 10

#define TEXT "bostenga"

int main() {

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    /*MaximizeWindow();*/
    InitWindow(WIDTH, HEIGHT, "Raylib");
    /*SetTargetFPS(MAX_FPS);*/

    Rectangle square = {
        .x = (float)WIDTH / 2,
        .y = (float)HEIGHT / 2,
        .width = SIZE,
        .height = SIZE,
    };

    while (!WindowShouldClose()) {

        ClearBackground(BLACK);

        float deltaTime = GetFrameTime();
        DrawFPS(1, 1);

        BeginDrawing();

        {
            DrawRectangle(square.x, square.y, SIZE, SIZE, GREEN);
            DrawText(TEXT, square.x + (float)SIZE / 4, square.y + ((float)SIZE / 2), 12, WHITE);
            Vector2 mouse_pos = GetMousePosition();

            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {

                printf("mouse: {x:%f, y:%f} \n", mouse_pos.x, mouse_pos.y);

                if (CheckCollisionPointRec(mouse_pos, square)) {
                    // printf("is inside square!\n");
                    square.x = mouse_pos.x - (float)SIZE / 2;
                    square.y = mouse_pos.y - (float)SIZE / 2;
                }
            }
        }
        EndDrawing();
    }
    return 0;
}
