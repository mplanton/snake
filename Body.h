// Body.h
#ifndef BODY_H
#define BODY_H
#include "Thing.h"

class Body : public Thing
{
private:
    Coord _position;
    Coord _direction;
public:
    enum Type
    {
        HEAD,
        TAIL
    };

    Body(Type type, Coord position, Coord direction) :
         Thing(BODY), _position{position}, _direction{direction}
    {
        switch(type)
        {
        case HEAD:
            _c = '@';
            break;
        case TAIL:
            _c = '#';
            break;
        }
    }

    // Get and set direction
    Coord get_dir() {return _direction;}
    void  set_dir(Coord direction) {_direction = direction;}
    // Get and set position
    Coord get_pos() {return _position;}
    void  set_pos(Coord position) {_position = position;}
};

#endif // BODY_H
