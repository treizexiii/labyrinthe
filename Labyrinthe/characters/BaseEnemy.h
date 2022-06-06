#ifndef BASE_ENEMY_H
#define BASE_ENEMY_H

#pragma once
#include "BaseCharacter.h"

enum EnemyType
{
    GREEN_ENEMY,
    RED_ENEMY,
};

class BaseEnemy : public BaseCharacter
{
private:
    BaseEnemy* _nextEnemy;
protected:
public:
    BaseEnemy() : BaseCharacter() { _nextEnemy = nullptr; }
    BaseEnemy(int x, int y) : BaseCharacter(x, y) { _nextEnemy = nullptr; }

    virtual void AutoMove();
    void CollisionTest() const;

    BaseEnemy* GetNextEnemy() const { return _nextEnemy; }
    void SetNextEnemy(BaseEnemy* enemy) { _nextEnemy = enemy; }
};

#endif
