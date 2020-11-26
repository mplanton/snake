// Random.cpp
#include<cstdlib>
#include<ctime>
#include "Random.h"

Random::Random()
{
   srand(time(NULL));
}

int Random::get_int(int min, int max)
{
    int r = rand() % (max - min);
    return r + min;
}

int Random::get_char(char min, char max)
{
    char c = rand() % (max - min);
    return c + min;
}

Coord Random::get_coord(int x_min, int x_max, int y_min, int y_max)
{
   int x = Random::get_int(x_min, x_max); 
   int y = Random::get_int(y_min, y_max); 
   return Coord(x, y);
}
