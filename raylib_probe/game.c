#include <raylib.h>

int main() {

    InitWindow(800, 600, "hello world");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(GREEN);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
