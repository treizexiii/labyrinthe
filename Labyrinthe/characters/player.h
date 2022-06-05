#pragma once
#include "BaseCharacter.h"

class Player : public BaseCharacter
{
public:
	Player() : BaseCharacter() {}
	Player(const int x, const int y) : BaseCharacter(x, y) {}
	void Draw() override;

private:

};
