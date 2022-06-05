#ifndef GREEN_ENEMY_H
#define GREEN_ENEMY_H

#pragma once
#include "BaseEnemy.h"

class GreenEnemy : public BaseEnemy
{
public:
    GreenEnemy() : BaseEnemy() {}
    GreenEnemy(const int x, const int y) : BaseEnemy(x, y) {}

    void Draw() override;
};

#endif
