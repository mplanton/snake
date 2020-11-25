// Thing.h
#ifndef THING_H
#define THING_H

// Base class for all things in the snake game.
//
class Thing
{
public:
    enum Type
    {
        AIR,
        BORDER,
        FOOD,
        BODY
    };

private:
    Type _type;

protected:
    char _c;

public:
    Thing(Type type);
    Type get_type() {return _type;}
    char get_char() {return _c;}
};

#endif // THING_H
