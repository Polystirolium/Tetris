#include "tetromino.h"
#include "tetris_object.h"

int main()
{
    const char *appName{"TETRIS"};
    const int windowDimensioms[2] = {1920, 1080};
    tetris_object tetris(12, 22);
    tetris.SetFieldPosition(550, 150);

    InitWindow(windowDimensioms[0], windowDimensioms[1], appName);

    SetTargetFPS(60);

    std::vector<int> vLines;

    // Игровой цикл
    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(BLACK);

        tetris.Tick(GetFrameTime());
        tetris.DrawNextTetramino(300, 500);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}