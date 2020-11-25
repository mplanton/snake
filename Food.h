// Food.h
#ifndef FOOD_H
#define FOOD_H
#include "Thing.h"

class Food : public Thing
{
public:
    Food() : Thing(FOOD)
    {
        _c = 'o';
    }
};

#endif // FOOD_H
