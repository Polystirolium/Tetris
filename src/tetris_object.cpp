#include "tetris_object.h"

tetris_object::tetris_object(int width, int height) : pField(new int[width * height]), nCurrentPiece(rand() % 7),
                                                      nNextPiece(rand() % 7), nCurrentX((width) / 2 - 2),
                                                      nCurrentY(0), nCurrentRotation(0)

{
    nFieldWidth_ = width;
    nFieldHeight_ = height;

    // Инициализация поля

    for (int x = 0; x < nFieldWidth_; x++)
        for (int y = 0; y < nFieldHeight_; y++)
        {
            if (x == 0)
                pField[y * nFieldWidth_ + x] = 2;
            if (x == nFieldWidth_ - 1)
                pField[y * nFieldWidth_ + x] = 3;
            if (y == (nFieldHeight_ - 2) && ((x != 0) && (x != nFieldWidth_ - 1)))
                pField[y * nFieldWidth_ + x] = 4;
            if (y == (nFieldHeight_ - 1) && ((x == 0) || (x == nFieldWidth_ - 1)))
                pField[y * nFieldWidth_ + x] = 0;
            if (y == (nFieldHeight_ - 1) && ((x != 0) && (x != nFieldWidth_ - 1)))
                pField[y * nFieldWidth_ + x] = 5;
            if ((x > 0 && x < nFieldWidth_ - 1) && (y >= 0 && y < nFieldHeight_ - 2))
                pField[y * nFieldWidth_ + x] = 1;
        }
    // Инициализация тетрамино
    tetramino.push_back(
        {0, 0, 1, 0,
         0, 0, 1, 0,
         0, 0, 1, 0,
         0, 0, 1, 0});
    tetramino.push_back(
        {0, 0, 1, 0,
         0, 1, 1, 0,
         0, 1, 0, 0,
         0, 0, 0, 0});
    tetramino.push_back(
        {0, 1, 0, 0,
         0, 1, 1, 0,
         0, 0, 1, 0,
         0, 0, 0, 0});
    tetramino.push_back(
        {0, 0, 0, 0,
         0, 1, 1, 0,
         0, 1, 1, 0,
         0, 0, 0, 0});
    tetramino.push_back(
        {0, 0, 1, 0,
         0, 1, 1, 0,
         0, 0, 1, 0,
         0, 0, 0, 0});
    tetramino.push_back(
        {0, 0, 0, 0,
         0, 1, 1, 0,
         0, 0, 1, 0,
         0, 0, 1, 0});
    tetramino.push_back(
        {0, 0, 0, 0,
         0, 1, 1, 0,
         0, 1, 0, 0,
         0, 1, 0, 0});
}

// Установка положения поля на экране
void tetris_object::SetFieldPosition(int x, int y)
{
    nFieldPosX_ = x;
    nFieldPosY_ = y;
}

// Отрисовка следующего тетрамино
void tetris_object::DrawNextTetramino(int posX, int posY)
{
    for (int px = 0; px < 4; px++)
        for (int py = 0; py < 4; py++)
        {
            int pi = Rotate(px, py, 0);
            if (tetramino[nNextPiece][pi])
                DrawElement(posX + 32 * px, posY + 33 * py, 6, bkColor, color);
        }
}

void tetris_object::MoveForceDown()
{
    if (((DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, nCurrentY + 1))) && bForceDown)
    {
        nCurrentY++;
    }
}

tetris_object::~tetris_object()
{
}

int tetris_object::Rotate(int px, int py, int r)
{
    switch (r % 4)
    {
    case 0:
        return py * 4 + px; // 0 градусов
    case 1:
        return 12 + py - (px * 4); // 90 градусов
    case 2:
        return 15 - (py * 4) - px; // 180 градусов
    case 3:
        return 3 - py + (px * 4); // 270 градусов
    }
    return 0;
}

bool tetris_object::DoesPieceFit(int nTetramino, int nRotation, int nPosX, int nPosY)
{
    {
        for (int px = 0; px < 4; px++)
            for (int py = 0; py < 4; py++)
            {
                int pi = Rotate(px, py, nRotation);
                int fi = (nPosY + py) * (nFieldWidth_) + (nPosX + px);

                if (nPosX + px >= 0 && nPosX + px < nFieldWidth_)
                {
                    if (nPosY + py >= 0 && nPosY + py < nFieldHeight_)
                    {
                        if (tetramino[nTetramino][pi] == 1 && (pField[fi] != 1))
                        {
                            return false;
                        }
                    }
                }
            }

        return true;
    }
}
void tetris_object::Timer(float deltaTime)
{
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.f;

        if (frame > maxFrame)
        {

            frame = 0;
        }
    }
}
void tetris_object::HoldingTimer(float deltaTime)
{
    holdingRunningTime += deltaTime;
    if (holdingRunningTime >= updateTime)
    {
        nHoldingFrame++;
        holdingRunningTime = 0.f;

        if (nHoldingFrame > maxFrame)
        {

            nHoldingFrame = 0;
            bLinesDeleting = false;
        }
    }
}
void tetris_object::RemoveTetramino()
{
    for (int px = 0; px < 4; px++)
        for (int py = 0; py < 4; py++)
            if (tetramino[nCurrentPiece][Rotate(px, py, nCurrentRotation)] == 1)
                pField[(nCurrentY + py) * (nFieldWidth_) + (nCurrentX + px)] = 1;
}

void tetris_object::PutTetramino()
{
    for (int px = 0; px < 4; px++)
        for (int py = 0; py < 4; py++)
            if (tetramino[nCurrentPiece][Rotate(px, py, nCurrentRotation)] == 1)
                pField[(nCurrentY + py) * nFieldWidth_ + (nCurrentX + px)] = 6;
}

void tetris_object::CheckLines()
{
    for (int py = 0; py < 4; py++)
    {
        if (nCurrentY + py < nFieldHeight_ - 2)
        {
            bool bLine = true;

            for (int px = 1; px < nFieldWidth_ - 1; px++)
            {
                if (bLine && pField[(nCurrentY + py) * nFieldWidth_ + px] == 6)
                {
                    bLine = true;
                }
                else
                {
                    bLine = false;
                }
            }

            // Подстановка знаков равно на место линии
            if (bLine)
            {
                for (int px = 1; px < nFieldWidth_ - 1; px++)
                    pField[(nCurrentY + py) * nFieldWidth_ + px] = 4;

                vLines.push_back(nCurrentY + py);
                bLinesDeleting = true;
            }
        }
    }
}

void tetris_object::NextTetramino()
{
    nCurrentPiece = nNextPiece;
    nNextPiece = rand() % 7;
    nCurrentRotation = 0;
    nCurrentX = nFieldWidth_ / 2 - 2;
    nCurrentY = 0;
    bForceDown = false;
}

void tetris_object::DrawField(int nFieldPosX, int nFieldPosY, Color bkColor, Color color)
{
    for (int x = 0; x < nFieldWidth_; x++)
        for (int y = 0; y < nFieldHeight_; y++)
        {
            DrawElement(nFieldPosX_ + x * nElementWidth_, nFieldPosY_ + y * nElementHeigth_,
                        pField[y * nFieldWidth_ + x], bkColor, color);
        }
}
void tetris_object::Tick(float deltaTime)
{
    // Таймер. Прибавление кадров
    Timer(deltaTime);

    // Затирка тетрамино
    RemoveTetramino();
    if (!bLinesDeleting)
    {
        if (DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, nCurrentY + 1))
        {
            if (frame == maxFrame)
                nCurrentY++;
        }
        else
        {
            PutTetramino();

            // Создана ли горизонтальная линия
            CheckLines();
            // Выбор следующего тетрамино F
            NextTetramino();
        }
        // Запись тетрамино в поле
        nCurrentRotation += (IsKeyPressed(KEY_UP) && DoesPieceFit(nCurrentPiece, nCurrentRotation + 1, nCurrentX, nCurrentY)) ? 1 : 0;
        nCurrentX += (IsKeyPressed(KEY_RIGHT) && DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX + 1, nCurrentY)) ? 1 : 0;
        nCurrentX -= (IsKeyPressed(KEY_LEFT)) && DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX - 1, nCurrentY) ? 1 : 0;
        nCurrentY += (IsKeyPressed(KEY_DOWN)) && DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, nCurrentY + 1) ? 1 : 0;

        if (IsKeyDown(KEY_SPACE))
            MoveForceDown();
        if (IsKeyReleased(KEY_SPACE))
            bForceDown = true;
    }
    else
    {
        HoldingTimer(deltaTime);
    }
    // Удаление линий
    if (!vLines.empty() && nHoldingFrame == maxFrame)
    {
        for (int &v : vLines)
            for (int px = 1; px < nFieldWidth_ - 1; px++)
            {
                for (int py = v; py > 0; py--)
                {
                    pField[py * nFieldWidth_ + px] = pField[(py - 1) * nFieldWidth_ + px];
                }
                pField[px] = 1;
            }
        vLines.clear();
        bLinesDeleting=false;
    }

    PutTetramino();

    DrawField(nFieldPosX_, nFieldPosY_, bkColor, color);
}