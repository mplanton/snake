// Snake.cpp

#include "Snake.h"

Snake::Snake(Coord position, Coord direction);
{
    Bopy head = Body(Body::HEAD, position, direction);
   _tail.push_back(head); 
    Bopy tail = Body(Body::TAIL, position-direction, direction);
   _tail.push_back(head); 
}

Action Snake::move();

void Snake::changeDirection(Direction direction);

Coord Snake::getHeadCoord();

std::vector<Body>& Snake::getBody();


// TODO: Make these methods private later on
// But now we need them for testing

// part of move()
void Snake::grow();

// part of move()
bool Snake::collisionDetect();
