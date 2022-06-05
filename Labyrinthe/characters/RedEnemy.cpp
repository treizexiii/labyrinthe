#include "RedEnemy.h"

void RedEnemy::Draw()
{
    glPushMatrix();
    glTranslated(0.5 + _posX, 0.5 + _posY, 0);
    glColor3d(0.9,0,0);
    glPushMatrix();
    glScaled(0.7,1.0,1.0);
    glutSolidSphere(0.35, 12,12);
    glPopMatrix();
    glPushMatrix();
    glScaled(1,0.7,1);
    glutSolidSphere(0.35,12,12);
    glPopMatrix();
    // eyes
    glColor3d(0,0,0);
    glTranslated(0.13,-0.05,0);
    glutSolidSphere(0.07, 12,12);
    glTranslated(-0.26,0,0);
    glutSolidSphere(0.07, 12,12);
    glPopMatrix();
}
