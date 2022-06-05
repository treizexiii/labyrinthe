#include "World.h"

#include <iostream>

#include "GL/glut.h"

World::World()
{
    _map = nullptr;
    _width = 0;
    _height = 0;
}

World::World(const std::string& filename)
{
    std::ifstream file;
    file.open(filename);
    if (file.good() == false)
    {
        std::cout << "Open file error" << std::endl;
        system("pause");
        exit(1);
    }
    file >> _width;
    file >> _height;

    _map = new char*[_width];
    for (int i = 0; i < _width; i++)
    {
        _map[i] = new char[_height];
        for (int j = 0; j < _height; j++)
        {
            _map[i][j] = '0';
        }
    }

    for (int j = 0; j < _height; j++)
    {
        for (int i = 0; i < _width; i++)
        {
            file >> _map[i][j];
        }
    }
    file.close();
}

int World::get_width() const
{
    return _width;
}

int World::get_heigth() const
{
    return _height;
}

void World::draw_map() const
{
    glColor3d(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    for (int i = 0; i < _width; i++)
    {
        for (int j = 0; j < _height; j++)
        {
            if (_map[i][j] == '1')
            {
                glVertex2d(i, j);
                glVertex2d(i, j + 1);
                glVertex2d(i + 1, j + 1);
                glVertex2d(i + 1, j);
            }
        }
    }
    glEnd();
}

void World::dispose_level() const
{
    if (_map != nullptr)
    {
        for (int i = 0; i < _width; i++)
        {
            delete[] _map[i];
        }
        delete[] _map;
    }
}
