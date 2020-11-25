// Map.cpp

#include <iostream>
#include <cstdlib>
#include "Map.h"
#include "Air.h"

Map::Map(int size_x, int size_y) : _size_x{size_x}, _size_y{size_y}
{
    if(size_x <= 0 || size_y <= 0)
    {
       std::cerr << "Map: Error! size_x and size_y must be positive integers!" << std::endl;
       exit(EXIT_FAILURE);
    }

    // initialize the map with empty space
    for(int i = 0; i < _size_y; i++)
    {
        std::vector<Thing> line;
        for(int j = 0; j < _size_x; j++)
        {
            line.push_back(Air());
        }
        _things.push_back(line);
    }
}

std::string Map::render()
{
    std::string str;

    for(std::vector<Thing> line : _things)
    {
        for(Thing thing : line)
        {
            str.push_back(thing.get_char());
        }
    str.push_back('\n');
    }

    return str;
}

bool Map::add(Thing thing, Coord position)
{
    unsigned int x = position.get_x();
    unsigned int y = position.get_y();

    // range check
    if(y < 0 || y >= _things.size() || x < 0 || x >= _things[0].size())
    {
        std::cerr << "Map.add(): Error! Index out of range!" << std::endl;
        std::cerr << "Cannot insert '" << thing.get_char() << "' thing "
                  << "at position x: " << x << " y: " << y << '!'
                  << std::endl;
        return false;
    }

    Thing old = _things[y][x];

    // It is only possible to add a thing if there is empty space at the
    // position.
    if(old.get_type() == Thing::AIR)
    {
        // TODO: do we have to delete the old object?
        _things[y][x] = thing;
        return true;
    }
    else
    {
        return false;
    }
}

Thing Map::remove(Coord position)
{
    unsigned int x = position.get_x();
    unsigned int y = position.get_y();
    Thing thing = _things[y][x];
    // TODO: make savety check, if it is a removable object
    // TODO: do we have to delete the old object?
    _things[y][x] = Air();
    return thing;
}

