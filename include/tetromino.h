#ifndef TETROMINO_H
#define TETROMINO_H

#include "raylib.h"
#include "raymath.h"
#include <vector>

void DrawElement(int pX, int pY, int id, Color cBkColor, Color color);
void DrawField(int nFieldPosX, int nFieldPosY, Color bkColor, Color color);

#endif