// Labyrinthe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "GL/glut.h"

using namespace std;

void labyAffichage();
void labyReshape(int x, int y);
void openLevel(const char* fileName);
void disposeLevel();

int nbLines = 0;
int nbColumns = 0;
char** Matrix;

int main()
{
	std::cout << "Hello World!\n";

	openLevel("level.txt");

	glutInitWindowPosition(10, 10);
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Labyrinthe");
	glutDisplayFunc(labyAffichage);
	glutReshapeFunc(labyReshape);
}



// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

void labyAffichage()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	// Run code here

	glFlush();
}

void labyReshape(int x, int y)
{
	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (double)nbColumns, (double)nbLines, 0);
}

void openLevel(char* fileName)
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
		}
	}
	file.close();
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
