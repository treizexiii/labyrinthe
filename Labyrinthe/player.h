class Player
{
public:
	int getPosX() const { return posX; }
	void setPosX(int x) { posX = x; }

	int getPosY() const { return posY; }
	void setPosY(int y) { posY = y; }

	Player() {
		posX = 0;
		posY = 0;
	}

	void draw();

private:
	int posX;
	int posY;
};