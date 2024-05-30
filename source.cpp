#include "tetromino.h"
#include "tetris_object.h"
#include "tetris_menu.h"
#include <ctime>

int main()
{
    srand(time(NULL));
    const char *appName{"TETRIS"};
    const int windowDimensioms[2] = {900, 800};
    tetris_object tetris(12, 22);
    tetris.SetFieldPosition(450, 50);

    Tetris_menu tetrisMenu;

    InitWindow(windowDimensioms[0], windowDimensioms[1], appName);

    SetTargetFPS(60);

    std::vector<int> vLines;

    // Игровой цикл
    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(BLACK);
        /*
                tetrisMenu.DrawTetrisText(0, 0);
                tetrisMenu.DrawImg(0, 374, {0, 255, 0, 255});
        */

        tetris.Tick(GetFrameTime());
        tetris.DrawNextTetramino(50, 250);
        DrawText(TextFormat("SCORE: %i", tetris.GetScore()), 50, 52, 30, tetris.GetColor());
        DrawText(TextFormat("TOTAL LINES: %i", tetris.GetLines()), 50, 102, 30, tetris.GetColor());
        DrawText(TextFormat("LEVEL: %i", tetris.GetLevel()), 50, 152, 30, tetris.GetColor());

        EndDrawing();
    }

    CloseWindow();

    return 0;
}