#include "tetromino.h"
#include "tetris_object.h"
#include "tetris_menu.h"

int main()
{
    const char *appName{"TETRIS"};
    const int windowDimensioms[2] = {1920, 1080};
    tetris_object tetris(12, 22);
    tetris.SetFieldPosition(550, 150);

    Tetris_menu tetrisMenu;

    InitWindow(windowDimensioms[0], windowDimensioms[1], appName);

    SetTargetFPS(60);

    std::vector<int> vLines;

    // Игровой цикл
    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(BLACK);

        tetrisMenu.DrawTetrisText(0, 0);
        /*
                tetris.Tick(GetFrameTime());
                tetris.DrawNextTetramino(300, 500);
                DrawText(TextFormat("SCORE: %i", tetris.GetScore()), 100, 150, 30, tetris.GetColor());
                DrawText(TextFormat("TOTAL LINES: %i", tetris.GetLines()), 100, 200, 30, tetris.GetColor());
                DrawText(TextFormat("LEVEL: %i", tetris.GetLevel()), 100, 250, 30, tetris.GetColor());
        */
        EndDrawing();
    }

    CloseWindow();

    return 0;
}