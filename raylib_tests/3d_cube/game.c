#include <math.h>
#include <raylib.h>
#include <raymath.h>

#define CUBE_SIZE 20
#define CUBE_COLOR GREEN
#define CAMERA_SPEED CUBE_SIZE

int main(void) {

    float camera_mag = CUBE_SIZE * 2;
    float camera_mag_vel = 0.0f;
    float camera_theta = 0.0f;
    float camera_phi = 0.0f;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(800, 600, "hello world");

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        camera_mag += camera_mag_vel * deltaTime;
        if (camera_mag < 0) {
            camera_mag = 0.0f;
        }

        camera_mag_vel -= GetMouseWheelMove() * CUBE_SIZE * 50;
        camera_mag_vel *= 0.9f;

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            Vector2 delta = GetMouseDelta();
            camera_theta -= delta.x * 0.01;
            /*camera_phi -= delta.y * 0.01;*/
        }

        ClearBackground(BLACK);

        BeginDrawing();
        {

            DrawFPS(1, 1);
            Camera3D camera = {
                .position = {
                    .x = sinf(camera_theta) * cosf(camera_phi) * camera_mag,
                    .y = sinf(camera_theta) * sinf(camera_phi) * camera_mag,
                    .z = cosf(camera_theta) * camera_mag,
                },
                .target = {0, 0, 0},
                .up = {0, 1, 0},
                .fovy = 90,
                .projection = CAMERA_PERSPECTIVE,
            };

            BeginMode3D(camera);
            {
                DrawCube(Vector3Zero(), CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, GREEN);
            }
            EndMode3D();
        }
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
