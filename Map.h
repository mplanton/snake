// Map.h
#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include "Coord.h"
#include "Thing.h"

class Map
{
    int _size_x;
    int _size_y;
    std::vector<std::vector<Thing>> _things;
public:
    // Constructor
    Map(int size_x, int size_y);

    // Render the map to a string
    std::string render();

    // Add a Thing to the Map
    // return true if possibe and false, if not.
    bool add(Thing thing, Coord position); 
    
    // Remove a Thing from the Map at the given coordinate.
    // Return the removed thing.
    Thing remove(Coord position);

    int get_size_x() { return _size_x; }
    int get_size_y() { return _size_y; }
    Coord get_size() { return Coord(_size_x, _size_y); }
    int get_num_things() { return _things.size(); }
};

#endif // MAP_H
