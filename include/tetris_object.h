#ifndef TETRIS_OBJECT_H
#define TETRIS_OBJECT_H

#include <vector>
#include "tetromino.h"

class tetris_object
{

public:
    tetris_object(int width, int height);
    void SetFieldPosition(int x, int y);
    void DrawNextTetramino(int posX, int posY);
    void Tick(float deltaTime);
    ~tetris_object();

private:
    // Параметры поля
    int nFieldWidth_;
    int nFieldHeight_;
    int *pField = nullptr;
    int nFieldPosX_ = 0;
    int nFieldPosY_ = 0;

    // Параметры тетрамино
    int nCurrentPiece;
    int nNextPiece;
    int nCurrentX;
    int nCurrentY;
    int nCurrentRotation;

    // Параметры элемента
    int nElementWidth_ = 33;
    int nElementHeigth_ = 32;
    Color bkColor{0, 255, 0, 255};
    Color color{0, 255, 125, 255};

    // Параметры кадра
    float runningTime{0.f};
    float holdingRunningTime{0.f};
    int frame{0};
    int nHoldingFrame{0};
    int maxFrame{30};
    float updateTime{1.f / 60.f};

    std::vector<std ::vector<int>> tetramino;
    std::vector<int> vLines;

    int Rotate(int px, int py, int r);
    bool DoesPieceFit(int nTetramino, int nRotation, int nPosX, int nPosY);
    bool bForceDown{true};
    bool bLinesDeleting{false};
    void MoveForceDown();
    void Timer(float deltaTime);
    void HoldingTimer(float deltaTime);
    void RemoveTetramino();
    void PutTetramino();
    void CheckLines();
    void NextTetramino();
    void DrawField(int nFieldPosX, int nFieldPosY, Color bkColor, Color color);
};

#endif