#include "player.h"
#include "GL/glut.h"

void Player::draw() {
	glPushMatrix();
	glTranslated(posX + 0.5, posY + 0.5, 0);
	glColor3d(0.0, 0.0, 0.0);
	glutSolidSphere(0.3, 12.0, 12.0);

	glColor3d(1.0, 1.0, 0.0);
	glTranslated(0.1, -0.1, 0.0);
	glutSolidSphere(0.05, 12, 12);
	glTranslated(-0.2, 0.0, 0.0);
	glutSolidSphere(0.05, 12, 12);
	glPopMatrix();
}