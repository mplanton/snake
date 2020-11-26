// Snake.h
#ifndef SNAKE_H
#define SNAKE_H
#include<vector>
#include "Coord.h"
#include "Thing.h"
#include "Body.h"

class Snake
{
private:
    // This includes head and tail -> maybe change this name later...
    std::vector<Body> _tail;

public:

    // Constructor
    //
    // position: starting position of the snake on the map
    // direction: starting direction of the snake
    //
    Snake(Coord position, Coord direction);

    // Move method of the Snake
    //
    // This moves the snake in the current direction
    //
    void move();
    
    // Steering of the snake
    //
    // Change the current direction of the snake
    //
    void changeDirection(Coord direction);

    // Return the coordinates of the snakes head
    //
    Coord getHeadCoord();

    // Print the coordinates of the whole snake
    //
    void printCoords();

    // Return a reference of the snakes body for rendering
    //
    std::vector<Body>& getBody();

    void grow();
};

#endif // SNAKE_H
