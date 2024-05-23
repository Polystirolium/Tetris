#ifndef TILEMAP_H
#define TILEMAP_H

#include "raylib.h"
#include "raymath.h"
#include <vector>

void DrawElement(int pX, int pY, int id, Color cBkColor, Color color);
void DrawField(int nFieldPosX, int nFieldPosY, Color bkColor, Color color);

#endif