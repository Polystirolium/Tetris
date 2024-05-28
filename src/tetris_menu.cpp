#include "tetris_menu.h"

Tetris_menu::Tetris_menu(/* args */)
{
}

void Tetris_menu::DrawTetrisText(int posX, int posY)
{
   DrawT(posX + 64, posY + 66);
   DrawE(posX + 384, posY + 66);
   DrawT(posX + 704, posY + 66);
}

Tetris_menu::~Tetris_menu()
{
}

void Tetris_menu::DrawBlock(int posX, int posY)
{
   DrawElement(posX, posY, 6, bkColor, color);
   DrawElement(posX + 32, posY, 6, bkColor, color);
   DrawElement(posX, posY + 33, 6, bkColor, color);
   DrawElement(posX + 32, posY + 33, 6, bkColor, color);
}

void Tetris_menu::DrawT(int posX, int posY)
{
   DrawBlock(posX, posY);
   DrawBlock(posX + 64, posY);
   DrawBlock(posX + 128, posY);

   DrawBlock(posX + 64, posY + 66);
   DrawBlock(posX + 64, posY + 132);
   DrawBlock(posX + 64, posY + 198);
}

void Tetris_menu::DrawE(int posX, int posY)
{
   DrawBlock(posX, posY);
   DrawBlock(posX, posY + 66);
   DrawBlock(posX, posY + 132);
   DrawBlock(posX, posY + 198);

   DrawElement(posX + 64, posY, 6, bkColor, color);
   DrawElement(posX + 96, posY, 6, bkColor, color);
   DrawElement(posX + 128, posY, 6, bkColor, color);
   DrawElement(posX + 160, posY, 6, bkColor, color);

   DrawElement(posX + 64, posY + 99, 6, bkColor, color);
   DrawElement(posX + 96, posY + 99, 6, bkColor, color);
   DrawElement(posX + 128, posY + 99, 6, bkColor, color);

   DrawElement(posX + 64, posY + 232, 6, bkColor, color);
   DrawElement(posX + 96, posY + 232, 6, bkColor, color);
   DrawElement(posX + 128, posY + 232, 6, bkColor, color);
   DrawElement(posX + 160, posY + 232, 6, bkColor, color);
}

void Tetris_menu::DrawR(int posX, int posY)
{
}
