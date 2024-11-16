#include "map.map"
#include <math.h>
#include <raylib.h>
#include <stdbool.h>

#define FOV 3.14159 / 2

int main(void) {

    Vector2 player_pos = {2, 2};
    float player_angle = 0;
    float fov = FOV;

    int screen_width = 800;
    int screen_height = 600;

    float ray_step = 0.01f;

    InitWindow(800, 600, "Raycaster");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        if (IsKeyDown(KEY_RIGHT)) {
            player_angle += 0.5f * GetFrameTime();
        }

        if (IsKeyDown(KEY_LEFT)) {
            player_angle -= 0.5f * GetFrameTime();
        }

        BeginDrawing();
        {
            ClearBackground(WHITE);
            for (int i = 0; i < screen_width; i++) {
                float ray_angle = (player_angle - fov / 2.0f) + ((float)i / (float)screen_width) * fov;
                bool hit_wall = false;
                float ray_distance = 0;
                float eye_x = cosf(ray_angle);
                float eye_y = sin(ray_angle);

                int test_x = (int)(player_pos.x + eye_x * ray_distance);
                int test_y = (int)(player_pos.y + eye_y * ray_distance);

                while (!hit_wall) {
                    ray_distance += ray_step * sqrtf(eye_x * eye_x + eye_y * eye_y);

                    int test_x = (int)(player_pos.x + eye_x * ray_distance);
                    int test_y = (int)(player_pos.y + eye_y * ray_distance);

                    if (test_x < 0 || test_x > 5 || test_y > 5 || test_y < 0) {
                        hit_wall = true;
                        ray_distance = 20.0f;
                    } else {
                        if (map[test_x][test_y] > 0) {
                            hit_wall = true;
                        }
                    }
                }

                int ceiling = (screen_height / 2.0f) - screen_height / ray_distance * 0.65;
                int floor = screen_height - ceiling;

                DrawRectangle(i, 0, 1, ceiling, BLACK);              // ceiling
                DrawRectangle(i, floor, 1, screen_height, BLACK);    // floor
                DrawRectangle(i, ceiling, 1, floor - ceiling, GRAY); // walls
                DrawRectangleLines(i, ceiling, 5, 5, RED);           // wall lines
            }
        }
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
