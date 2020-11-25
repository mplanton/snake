// Body.h
#ifndef BODY_H
#define BODY_H
#include "Thing.h"

class Body : public Thing
{
private:
    Coord _direction;
    Coord _pos;
public:
    enum Type
    {
        HEAD,
        TAIL
    };

    Body(Type type) : Thing(BODY)
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
};

#endif // BODY_H
