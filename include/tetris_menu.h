#ifndef TETRIS_MENU_H
#define TETRIS_MENU_H

#include "tetromino.h"

class Tetris_menu
{

public:
    Tetris_menu(/* args */);
    void DrawTetrisText(int posX, int posY);
    ~Tetris_menu();

private:
    void DrawBlock(int posX, int posY);
    void DrawT(int posX, int posY);
    void DrawE(int posX, int posY);
    void DrawR(int posX, int posY);
    Color bkColor{0, 255, 0, 255};
    Color color{0, 255, 125, 255};
};

#endif