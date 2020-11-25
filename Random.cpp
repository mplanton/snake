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
