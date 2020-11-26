// Coord.cpp
#include "Coord.h"

Coord::Coord(int x, int y) : _x{x}, _y{y}
{ }

// object representation
std::ostream& operator<<(std::ostream &strm, Coord const &a)
{
    return strm << '(' << a.get_x() << ',' << a.get_y()<< ")";
}
