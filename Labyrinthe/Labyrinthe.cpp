// Labyrinthe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <ctime>
#include "GL/glut.h"
#include "characters/player.h"
#include "World.h"
#include "characters/GreenEnemy.h"
#include "characters/RedEnemy.h"

using namespace std;

int main();
void LabyDisplay();
void LabyReshape(int x, int y);
void LabySpecialKey(int key, int x, int y);
void OpenLevel(char fileName[]);
void DrawLevel();
void AddEnemy(int x, int y, EnemyType type);
void LabyTimer(int value);
void IsVictory();
void DisposeMemory();
void ExitGame(string message);

const int TIMER = 500;

int NB_LINES = 0;
int NB_COLUMNS = 0;
char** MATRIX;
int EXIT_X = 0;
int EXIT_Y = 0;

World world;
Player player;
BaseEnemy* firstEnemy = nullptr;

int main()
{
    std::cout << "Hello World!\n";
    srand(static_cast<int>(time(nullptr)));

    char level[] = "level.txt";
    OpenLevel(level);

    // const string& filename = "level.txt";
    // world = World(filename);

    glutInitWindowPosition(10, 10);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutCreateWindow("Labyrinthe");
    glutDisplayFunc(LabyDisplay);
    glutReshapeFunc(LabyReshape);
    glutSpecialFunc(LabySpecialKey);
    glutTimerFunc(TIMER, LabyTimer, 0);

    glutMainLoop();
}

void LabyDisplay()
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    // Run code here
    DrawLevel();
    // world.draw_map();
    player.Draw();

    BaseEnemy* currentEnemy = firstEnemy;
    while (currentEnemy != nullptr)
    {
        currentEnemy->Draw();
        currentEnemy = currentEnemy->GetNextEnemy();
    }

    glutSwapBuffers();
}

void LabyReshape(int x, int y)
{
    glViewport(0.0, 0.0, x, y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (double)NB_COLUMNS, (double)NB_LINES, 0.0);
}

void LabySpecialKey(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        player.MoveUp();
        break;
    case GLUT_KEY_DOWN:
        player.MoveDown();
        break;
    case GLUT_KEY_RIGHT:
        player.MoveRight();
        break;
    case GLUT_KEY_LEFT:
        player.MoveLeft();
        break;
    default:
        break;
    }
    const BaseEnemy* currentEnemy = firstEnemy;
    while (currentEnemy != nullptr)
    {
        currentEnemy->CollisionTest();
        currentEnemy = currentEnemy->GetNextEnemy();
    }
    IsVictory();

    glutPostRedisplay();
}

void OpenLevel(char fileName[])
{
    ifstream file;
    file.open(fileName);
    if (file.good() == false)
    {
        cout << "Erreur lors de l'ouverture du ficher" << endl;
        system("pause");
        exit(1);
    }

    file >> NB_COLUMNS;
    file >> NB_LINES;

    MATRIX = new char*[NB_COLUMNS];
    for (int i = 0; i < NB_COLUMNS; i++)
    {
        MATRIX[i] = new char[NB_LINES];
    }
    for (int i = 0; i < NB_COLUMNS; i++)
    {
        for (int j = 0; j < NB_LINES; j++)
        {
            MATRIX[i][j] = '0';
        }
    }
    for (int j = 0; j < NB_LINES; j++)
    {
        for (int i = 0; i < NB_COLUMNS; i++)
        {
            file >> MATRIX[i][j];
            switch (MATRIX[i][j])
            {
            case 'p':
            case 'P':
                player.SetPosX(i);
                player.SetPosY(j);
                break;
            case 'g':
            case 'G':
                AddEnemy(i, j, EnemyType::GREEN_ENEMY);
                break;
            case 'r':
            case 'R':
                AddEnemy(i, j, EnemyType::RED_ENEMY);
                break;
            case 's':
            case 'S':
                EXIT_X = i;
                EXIT_Y = j;
                break;
            default:
                break;
            }
        }
    }
    file.close();
}

void DrawLevel()
{
    glColor3d(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);

    for (int i = 0; i < NB_COLUMNS; i++)
    {
        for (int j = 0; j < NB_LINES; j++)
        {
            if (MATRIX[i][j] == '0')
            {
                glVertex2d(i, j);
                glVertex2d(i, j + 1);
                glVertex2d(i + 1, j + 1);
                glVertex2d(i + 1, j);
            }
        }
    }
    glEnd();

    glPushMatrix();
    glTranslated(EXIT_X + 0.5, EXIT_Y + 0.5, 0);
    glColor3d(0.3, 1, 0.3);
    for (double size = 0.1; size < 1.0; size += 0.2)
    {
        glutWireCube(size);
    }
    glPopMatrix();
}

void AddEnemy(int x, int y, EnemyType type)
{
    BaseEnemy* newEnemy = nullptr;
    switch (type)
    {
    case GREEN_ENEMY:
        newEnemy = new GreenEnemy(x, y);
        break;
    case RED_ENEMY:
        newEnemy = new RedEnemy(x, y);
        break;
    }
    newEnemy->SetNextEnemy(firstEnemy);
    firstEnemy = newEnemy;
}

void LabyTimer(int value)
{
    cout << "timer function" << endl;

    BaseEnemy* currentEnemy = firstEnemy;
    while (currentEnemy != nullptr)
    {
        currentEnemy->AutoMove();
        currentEnemy->CollisionTest();
        currentEnemy = currentEnemy->GetNextEnemy();
    }

    glutPostRedisplay();
    glutTimerFunc(TIMER, LabyTimer, 0);
}

void IsVictory()
{
    if (player.GetPosX() == EXIT_X && player.GetPosY() == EXIT_Y)
    {
        ExitGame("You win!!!");
    }
}

void DisposeMemory()
{
    if (MATRIX != nullptr)
    {
        for (int i = 0; i < NB_COLUMNS; i++)
        {
            delete[] MATRIX[i];
        }
        delete[] MATRIX;
    }
    while (firstEnemy != nullptr)
    {
        BaseEnemy* nextEnemy = firstEnemy->GetNextEnemy();
        delete firstEnemy;
        firstEnemy = nextEnemy;
    }
}

void ExitGame(string message)
{
    cout << message + "\a" << endl;
    LabyDisplay();
    DisposeMemory();
    system("pause");
    exit(1);
}
