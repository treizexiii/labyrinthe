// Labyrinthe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "GL/glut.h"
#include "player.h"

using namespace std;

void labyAffichage();
void labyReshape(int x, int y);
void openLevel(char fileName[]);
void drawLevel();
void disposeLevel();

int nbLines = 0;
int nbColumns = 0;
char** Matrix;

Player player1;

int main()
{
	std::cout << "Hello World!\n";

	char level[] = "level.txt";

	openLevel(level);

	glutInitWindowPosition(10, 10);
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutCreateWindow("Labyrinthe");
	glutDisplayFunc(labyAffichage);
	glutReshapeFunc(labyReshape);

	glutMainLoop();
}

void labyAffichage()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	// Run code here
	drawLevel();
	player1.draw();

	glFlush();
}

void labyReshape(int x, int y)
{
	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (double)nbColumns, (double)nbLines, 0);
}

void openLevel(char fileName[])
{
	ifstream file;
	file.open(fileName);
	if (file.good() == false) {
		cout << "Erreur lors de l'ouverture du ficher" << endl;
		system("pause");
		exit(1);
	}

	file >> nbColumns;
	file >> nbLines;

	Matrix = new char* [nbColumns];
	for (int i = 0; i < nbColumns; i++)
	{
		Matrix[i] = new char[nbLines];
	}
	for (int i = 0; i < nbColumns; i++)
	{
		for (int j = 0; j < nbLines; j++)
		{
			Matrix[i][j] = '0';
		}
	}

	for (int j = 0; j < nbLines; j++)
	{
		for (int i = 0; i < nbColumns; i++)
		{
			file >> Matrix[i][j];

			switch (Matrix[i][j])
			{
			case 'J':
			case 'j':
				player1.setPosX(i);
				player1.setPosY(j);
				break;
			default:
				break;
			}
		}
	}
	file.close();
}

void drawLevel()
{
	glColor3d(0.5, 0.5, 0.5);
	glBegin(GL_QUADS);

	for (int i = 0; i < nbColumns; i++)
	{
		for (int j = 0; j < nbLines; j++)
		{
			if (Matrix[i][j] == '0') {
				glVertex2d(i, j);
				glVertex2d(i, j + 1);
				glVertex2d(i + 1, j + 1);
				glVertex2d(i + 1, j);
			}
		}
	}
	glEnd();
}

void disposeLevel()
{
	if (Matrix != NULL) {
		for (int i = 0; i < nbColumns; i++)
		{
			delete[] Matrix[i];
		}
		delete[] Matrix;
	}
}
