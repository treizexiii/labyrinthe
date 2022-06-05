#include "BaseEnemy.h"
#include "player.h"
#include "../Core/Directions.h"

extern Player player;
extern void DisposeMemory();
extern void ExitGame(string message);

void BaseEnemy::AutoMove()
{
    const int directions = rand() % 4;
    switch (directions)
    {
    case UP:
        MoveUp();
        break;
    case DOWN:
        MoveDown();
        break;
    case LEFT:
        MoveLeft();
        break;
    case RIGHT:
        MoveRight();
        break;
    default:
        break;
    }
}

void BaseEnemy::CollisionTest() const
{
    if (_posX == player.GetPosX() && _posY == player.GetPosY())
    {
        ExitGame("You lose!!!");
    }
}
