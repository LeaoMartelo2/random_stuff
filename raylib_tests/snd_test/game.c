#include <raylib.h>

int main(void) {

    InitWindow(800, 600, "Snd test");
    InitAudioDevice();

    Sound test_snd = LoadSound("snd_button.wav");

    while (!WindowShouldClose()) {

        BeginDrawing();
        {
            PlaySound(test_snd);
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
