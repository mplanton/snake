// Coord.h
#ifndef COORD_H
#define COORD_H

class Coord
{
private:
    int _x, _y;
public:
    Coord() { } // default constructor
    Coord(int x, int y);
    int get_x() {return _x;}
    int get_y() {return _y;}
    // TODO: Methode, die stream oder string ausgibt, der die Koordinate darstellt.
};

#endif // COORD_H
