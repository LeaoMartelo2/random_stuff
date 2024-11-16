#include <raylib.h>

int main(void) {

    const int screen_width = 800;
    const int screen_height = 600;

    InitWindow(screen_width, screen_height, "3D test");
    SetTargetFPS(60);

    Camera3D camera = {0};
    camera.position = (Vector3){10.0f, 10.0f, 10.0f}; // Camera position
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};      // Camera looking at point
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                              // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;           // Camera projection type

    Vector3 cube_pos = {0, 0, 0};
    DisableCursor();

    while (!WindowShouldClose()) {

        UpdateCamera(&camera, CAMERA_FREE);

        if (IsKeyPressed(KEY_Z)) {
            camera.target = cube_pos;
        }

        BeginDrawing();
        {
            ClearBackground(BLACK);

            BeginMode3D(camera);
            {
                /*DrawCube(cube_pos, 5, 5, 5, GREEN);*/
                DrawCubeWires(cube_pos, 5, 5, 5, RED);
            }
            EndMode3D();
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
