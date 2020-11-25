// Air.h
#ifndef AIR_H
#define AIR_H
#include "Thing.h"

class Air : public Thing
{
public:
    Air() : Thing(AIR)
    {
        _c = ' ';
    }
};

#endif // AIR_H
