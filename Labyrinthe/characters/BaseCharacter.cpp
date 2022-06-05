#include "BaseCharacter.h"

extern int NB_COLUMNS;
extern int NB_LINES;
extern char** MATRIX;

BaseCharacter::BaseCharacter()
{
    _posX = 0;
    _posY = 0;
}

BaseCharacter::BaseCharacter(int x, int y)
{
    _posX = x;
    _posY = y;
}

Vector2 BaseCharacter::GetPosition()
{
    return {_posX, _posY};
}

int BaseCharacter::GetPosX() const
{
    return _posX;
}

int BaseCharacter::GetPosY() const
{
    return _posY;
}

void BaseCharacter::SetPosX(int x)
{
    _posX = x;
}

void BaseCharacter::SetPosY(int y)
{
    _posY = y;
}

void BaseCharacter::MoveUp()
{
    if (_posY > 0 && MATRIX[_posX][_posY - 1] != '0')
        _posY--;
}

void BaseCharacter::MoveDown()
{
    if (_posY < NB_LINES - 1 && MATRIX[_posX][_posY + 1] != '0')
        _posY++;
}

void BaseCharacter::MoveRight()
{
    if (_posX < NB_COLUMNS - 1 && MATRIX[_posX + 1][_posY] != '0')
        _posX++;
}

void BaseCharacter::MoveLeft()
{
    if (_posX > 0 && MATRIX[_posX - 1][_posY] != '0')
        _posX--;
}
