// Coord.h
#ifndef COORD_H
#define COORD_H
#include<iostream>

class Coord
{
private:
    int _x, _y;
public:
    Coord() { } // default constructor

    Coord(int x, int y); // constructor

    // getter
    int get_x() const {return _x;}
    int get_y() const {return _y;}

    Coord operator+(const Coord& b)
    {
        Coord sum;
        sum._x = this->_x + b._x;
        sum._y = this->_y + b._y;
        return sum;
    }

    Coord operator-(const Coord& b)
    {
        Coord sum;
        sum._x = this->_x - b._x;
        sum._y = this->_y - b._y;
        return sum;
    }

    bool operator==(const Coord& b)
    {
        return (this->_x == b._x) && (this->_y == b._y);
    }

    // unary minus operator overloading
    Coord operator-() const
    {
       Coord c;
       c._x = -_x;
       c._y = -_y;
       return c;
    }

    friend std::ostream& operator<<(std::ostream &strm, const Coord &a);
};

#endif // COORD_H
