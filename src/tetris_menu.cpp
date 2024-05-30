#include "tetris_menu.h"

Tetris_menu::Tetris_menu(/* args */)
{
}

void Tetris_menu::DrawTetrisText(int posX, int posY)
{
   DrawT(posX + 64, posY + 66);
   DrawE(posX + 384, posY + 66);
   DrawT(posX + 704, posY + 66);
   DrawR(posX + 1024, posY + 66);
   DrawI(posX + 1344, posY + 66);
   DrawS(posX + 1664, posY + 66);
}

void Tetris_menu::DrawImg(int posX, int posY, Color baseColor)
{
   // Line 0
   DrawCircle(posX + 13, posY + 12, 2.f, {0, 164, 0, 255});
   DrawCircle(posX + 26, posY + 12, 2.f, {0, 164, 0, 255});
   DrawCircle(posX + 39, posY + 12, 2.f, {0, 164, 0, 255});
   DrawCircle(posX + 52, posY + 12, 2.f, {0, 164, 0, 255});
   DrawCircle(posX + 65, posY + 12, 2.f, {0, 165, 0, 255});
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
   DrawBlock(posX, posY);
   DrawBlock(posX, posY + 66);
   DrawBlock(posX, posY + 132);
   DrawBlock(posX, posY + 198);

   DrawElement(posX + 64, posY, 6, bkColor, color);
   DrawElement(posX + 96, posY, 6, bkColor, color);

   DrawElement(posX + 64, posY + 132, 6, bkColor, color);
   DrawElement(posX + 96, posY + 132, 6, bkColor, color);

   DrawBlock(posX + 128, posY + 33);
   DrawElement(posX + 128, posY + 99, 6, bkColor, color);
   DrawElement(posX + 160, posY + 99, 6, bkColor, color);
}

void Tetris_menu::DrawI(int posX, int posY)
{
   DrawBlock(posX, posY);
   DrawBlock(posX, posY + 66);
   DrawBlock(posX, posY + 132);
   DrawBlock(posX, posY + 198);

   DrawElement(posX + 64, posY + 132, 6, bkColor, color);
   DrawElement(posX + 64, posY + 165, 6, bkColor, color);

   DrawElement(posX + 96, posY + 99, 6, bkColor, color);
   DrawElement(posX + 96, posY + 132, 6, bkColor, color);

   DrawBlock(posX + 128, posY);
   DrawBlock(posX + 128, posY + 66);
   DrawBlock(posX + 128, posY + 132);
   DrawBlock(posX + 128, posY + 198);
}

void Tetris_menu::DrawS(int posX, int posY)
{
   DrawElement(posX + 33, posY, 6, bkColor, color);
   DrawElement(posX + 66, posY, 6, bkColor, color);
   DrawElement(posX + 99, posY, 6, bkColor, color);
   DrawElement(posX + 131, posY, 6, bkColor, color);
   DrawElement(posX + 131, posY + 33, 6, bkColor, color);
   DrawElement(posX + 163, posY + 33, 6, bkColor, color);

   DrawBlock(posX, posY + 33);
   DrawBlock(posX, posY + 99);
   DrawBlock(posX, posY + 165);

   DrawElement(posX + 33, posY + 232, 6, bkColor, color);
   DrawElement(posX + 66, posY + 232, 6, bkColor, color);
   DrawElement(posX + 99, posY + 232, 6, bkColor, color);
   DrawElement(posX + 131, posY + 232, 6, bkColor, color);

   DrawElement(posX + 131, posY + 199, 6, bkColor, color);
   DrawElement(posX + 163, posY + 199, 6, bkColor, color);
}
