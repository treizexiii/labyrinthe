#include "GreenEnemy.h"

void GreenEnemy::Draw()
{
    glPushMatrix();
    glTranslated(0.5 + _posX, 0.5 + _posY, 0);
    glColor3d(0,0.9,0);
    glutSolidSphere(0.3, 12,12);
    glPushMatrix();
    glTranslated(0,-0.13,0);
    glScaled(1,0.5,1);
    glutSolidCube(0.5);
    glPopMatrix();
    glColor3d(1,0,0);
    glTranslated(-0.3,-0.1,0);
    for (int i = 0; i < 3; ++i)
    {
        glTranslated(0.15, 0, 0);
        glutSolidSphere(0.05, 12,12);
    }
    glPopMatrix();
}
