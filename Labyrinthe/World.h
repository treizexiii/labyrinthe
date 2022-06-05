#pragma once
#include <fstream>

class World
{
public:
    World();
    World(const std::string& filename);
    int get_width() const;
    int get_heigth() const;
    void draw_map() const;
    void dispose_level() const;
private:
    char** _map{};
    int _width{};
    int _height{};
};
