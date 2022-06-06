# ifndef RED_ENEMY_H
#define RED_ENEMY_H

#pragma once
#include "BaseEnemy.h"

extern void AddEnemy(int x, int y, EnemyType type);

class RedEnemy : public BaseEnemy
{
public:
    RedEnemy() : BaseEnemy() {}
    RedEnemy(const int x, const int y) : BaseEnemy(x,y) {}

    void Draw() override;
    void AutoMove() override;
};

#endif
