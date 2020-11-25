// Random.h
#ifndef RANDOM_H
#define RANDOM_H

class Random
{
public:
    // Constructor
    Random();

    // Return a random int between min and max excluding max.
    int get_int(int min, int max);

    // Return a random char between min and max excluding max.
    int get_char(char min, char max);

    // Return a random float between min and max.
    //float get_float(float min, float max);
};

#endif // RANDOM_H
