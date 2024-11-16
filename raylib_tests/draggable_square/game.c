#include <raylib.h>
#include <stdbool.h>

#define MAX_FPS 1000
#define WIDTH 900
#define HEIGHT 600
#define SIZE 100
#define SPEED 10
#define MAX_SIZE 501

#define TEXT "roblox"

void resize_square(Rectangle *square) {

    float deltaTime = GetFrameTime();

    /*printf("square {width:%f, height:%f} \n", square->width, square->height);*/

    if (IsKeyDown(KEY_S)) {
        if (square->height + 1 <= MAX_SIZE) {
            square->height = square->height + GetFPS() * deltaTime;
        }
    }

    if (IsKeyDown(KEY_W)) {
        if (square->height - 1 >= 100) {
            square->height = square->height - GetFPS() * deltaTime;
        }
    }

    if (IsKeyDown(KEY_D)) {
        if (square->width + 1 <= MAX_SIZE) {
            square->width = square->width + GetFPS() * deltaTime;
        }
    }

    if (IsKeyDown(KEY_A)) {
        if (square->width - 1 >= 100) {
            square->width = square->width - GetFPS() * deltaTime;
        }
    }
}

int main() {

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WIDTH, HEIGHT, "Raylib");
    SetTargetFPS(MAX_FPS);
    SetWindowIcon(LoadImage("resources/image.png"));
    SetExitKey(KEY_NULL);
    InitAudioDevice();

    Sound button_snd = LoadSound("resources/sound.mp3");
    Texture2D thirty = LoadTexture("resources/image.png");

    Rectangle square = {
        .x = (float)WIDTH / 2,
        .y = (float)HEIGHT / 2,
        .width = 100,
        .height = 100,
    };

    Rectangle button = {
        .x = (float)WIDTH - thirty.width - 5,
        .y = (float)5,
        .width = thirty.width,
        .height = thirty.height,
    };
    bool button_action = false;

    while (!WindowShouldClose()) {

        ClearBackground(BLACK);

        Vector2 mouse_pos = GetMousePosition();
        float deltaTime = GetFrameTime();
        DrawFPS(1, 1);

        resize_square(&square);

        Vector2 square_pos = {square.x, square.y};
        Vector2 square_size = {square.width, square.height};

        button_action = false;

        /*printf("mouse: {x:%f, y:%f} \n", mouse_pos.x, mouse_pos.y);*/

        // draggable square
        if (CheckCollisionPointRec(mouse_pos, square)) {

            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
                SetMouseCursor(MOUSE_CURSOR_RESIZE_ALL);
                /*printf("is inside square!\n");*/
                square.x = mouse_pos.x - square.width / 2;
                square.y = mouse_pos.y - square.height / 2;
            } else {
                SetMouseCursor(MOUSE_CURSOR_DEFAULT);
            }
        }

        // snd button

        if (CheckCollisionPointRec(mouse_pos, button)) {
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                button_action = true;
            }
        }

        if (button_action) {
            /*printf("audio played\n");*/
            PlaySound(button_snd);
        }

        BeginDrawing();
        {
            // snd button
            /*DrawRectangle(button.x, button.y, button.width, button.height, RED);*/
            /*DrawTexture(thirty, button.x, button.y, WHITE);*/

            // draggable square
            DrawRectangleV(square_pos, square_size, GREEN);
            DrawText(TEXT, square.x + (square.width / 2) - 2, square.y + (square.height / 2), 20, WHITE);
        }
        EndDrawing();
    }
    UnloadTexture(thirty);
    CloseWindow();
    return 0;
}
