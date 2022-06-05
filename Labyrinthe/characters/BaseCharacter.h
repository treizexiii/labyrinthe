#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H
#pragma once

#include <iostream>

#include "../Core/Vector2.h"
#include "../GL/glut.h"

using namespace std;

class BaseCharacter
{
protected:
    int _posX;
    int _posY;
    Vector2 _position;

public:
    BaseCharacter();
    BaseCharacter(int x, int y);

    Vector2 GetPosition();
    int GetPosX() const;
    int GetPosY() const;
    void SetPosX(int x);
    void SetPosY(int y);
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();

    virtual void Draw() = 0;
};

#endif
