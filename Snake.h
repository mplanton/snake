// Snake.h
#ifndef SNAKE_H
#define SNAKE_H
#include "Thing.h"
#include "Body.h"

class Snake:
{
private:
    std::vector<Body> _tail;

public:
    enum Action
    {
        EATS,       // the snake found food and grows
        COLLIDES,   // the snake collided with a border or itself 
        MOVES       // nothing happened, the snake just moved
    };

    enum Direction
    {
        UP,
        DOWN,
        RIGHT,
        LEFT
    };

    // Constructor
    //
    // position: starting position of the snake on the map
    // direction: starting direction of the snake
    //
    Snake(Coord position, Direction direction);

    // Move method of the Snake
    //
    // This moves the snake in the current direction and returns
    // the Action of the snake.
    //
    Action move();
    
    // Steering of the snake
    //
    // Change the current direction of the snake
    //
    void changeDirection(Direction direction);

    // Return the coordinates of the snakes head
    //
    Coord getHeadCoord();

    // Return a reference of the snakes body for rendering
    //
    std::vector<Body>& getBody();


    // TODO: Make these methods private later on
    // But now we need them for testing

    // part of move()
    void grow();

    // part of move()
    bool collisionDetect();
}

#endif // SNAKE_H
