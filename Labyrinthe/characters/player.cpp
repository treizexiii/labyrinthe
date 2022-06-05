#include "player.h"

void Player::Draw()
{
    glPushMatrix();
    glTranslated(0.5 + _posX, _posY + 0.5, 0);
    glColor3d(0.0, 0.0, 0.0);
    glutSolidSphere(0.3, 12.0, 12.0);

    glColor3d(1.0, 1.0, 0.0);
    glTranslated(0.1, -0.1, 0.0);
    glutSolidSphere(0.05, 12, 12);
    glTranslated(-0.2, 0.0, 0.0);
    glutSolidSphere(0.05, 12, 12);
    glPopMatrix();
}
