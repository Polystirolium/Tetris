#include "tetromino.h"


void DrawElement(int pX, int pY, int id, Color cBkColor, Color color)
{
    switch (id)
    {
    case 0:
        break;
    case 1:
        DrawRectangle(pX + 23, pY + 28, 4, 4, cBkColor);
        DrawRectangle(pX + 24, pY + 29, 3, 3, color);
        break;

    case 2:
        // Скобка <
        DrawLineEx({pX + 18.f, pY + 7.f}, {pX + 3.f, pY + 18.f}, 3.f, cBkColor);
        DrawLineEx({pX + 3.f, pY + 18.f}, {pX + 18.f, pY + 30.f}, 3.f, cBkColor);
        DrawLineEx({pX + 18.f, pY + 7.f}, {pX + 3.f, pY + 18.f}, 2.f, color);
        DrawLineEx({pX + 3.f, pY + 18.f}, {pX + 18.f, pY + 30.f}, 2.f, color);

        // Воскилицательный знак

        DrawRectangle(pX + 23, pY + 5, 5, 13, cBkColor);
        DrawRectangle(pX + 24, pY + 5, 3, 13, color);
        DrawRectangle(pX + 24, pY + 18, 3, 6, cBkColor);
        DrawRectangle(pX + 25, pY + 18, 1, 6, color);
        DrawRectangle(pX + 23, pY + 28, 5, 4, cBkColor);
        DrawRectangle(pX + 24, pY + 28, 3, 4, color);

        break;

    case 3:
        // Воскилицательный знак

        DrawRectangle(pX + 2, pY + 5, 5, 13, cBkColor);
        DrawRectangle(pX + 3, pY + 5, 3, 13, color);

        DrawRectangle(pX + 3, pY + 18, 3, 6, cBkColor);
        DrawRectangle(pX + 4, pY + 18, 1, 6, color);

        DrawRectangle(pX + 2, pY + 28, 5, 4, cBkColor);
        DrawRectangle(pX + 3, pY + 28, 3, 4, color);

        // Скобка >
        DrawLineEx({pX + 12.f, pY + 7.f}, {pX + 27.f, pY + 18.f}, 3.f, cBkColor);
        DrawLineEx({pX + 27.f, pY + 18.f}, {pX + 12.f, pY + 30.f}, 3.f, cBkColor);

        DrawLineEx({pX + 12.f, pY + 7.f}, {pX + 27.f, pY + 18.f}, 2.f, color);
        DrawLineEx({pX + 27.f, pY + 18.f}, {pX + 12.f, pY + 30.f}, 2.f, color);

        break;
    case 4:
        // ==
        DrawRectangle(pX + 2, pY + 13, 12, 3, cBkColor);
        DrawRectangle(pX + 3, pY + 15, 10, 1, color);

        DrawRectangle(pX + 2, pY + 20, 12, 3, cBkColor);
        DrawRectangle(pX + 3, pY + 21, 10, 1, color);

        DrawRectangle(pX + 18, pY + 13, 12, 3, cBkColor);
        DrawRectangle(pX + 19, pY + 15, 10, 1, color);

        DrawRectangle(pX + 18, pY + 20, 12, 3, cBkColor);
        DrawRectangle(pX + 19, pY + 21, 10, 1, color);

        break;

    case 5:
        // \/
        DrawLineEx({pX + 3.f, pY + 10.f}, {pX + 12.f, pY + 32.f}, 3.f, cBkColor);
        DrawLineEx({pX + 3.f, pY + 10.f}, {pX + 12.f, pY + 32.f}, 1.f, color);
        DrawLineEx({pX + 19.f, pY + 32.f}, {pX + 28.f, pY + 10.f}, 3.f, cBkColor);
        DrawLineEx({pX + 19.f, pY + 32.f}, {pX + 28.f, pY + 10.f}, 1.f, color);
        break;

    case 6:
        // Скобки
        DrawRectangle(pX + 3, pY + 2, 4, 31, color);
        DrawRectangle(pX + 7, pY + 2, 4, 4, color);
        DrawRectangle(pX + 7, pY + 29, 4, 4, color);
        DrawRectangle(pX + 23, pY + 2, 4, 4, color);
        DrawRectangle(pX + 23, pY + 29, 4, 4, color);
        DrawRectangle(pX + 27, pY + 2, 4, 31, color);

        break;

    default:
        break;
    }
}





