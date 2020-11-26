// Snake.cpp

#include "Snake.h"

Snake::Snake(Coord position, Coord direction)
{
    Body head = Body(Body::HEAD, position, direction);
   _tail.push_back(head); 
    Body tail = Body(Body::TAIL, position-direction, direction);
   _tail.push_back(tail); 
}

void Snake::move()
{
    // relocate head
    Coord old_pos = _tail[0].get_pos();
    Coord old_dir = _tail[0].get_dir();
    Coord new_pos =  old_pos + old_dir;
    _tail[0].set_pos(new_pos);

    // update tail
    for(unsigned int i = 1; i < _tail.size(); i++)
    {
        Coord next_pos = _tail[i].get_pos();
        Coord next_dir = _tail[i].get_dir();
        _tail[i].set_pos(old_pos); 
        _tail[i].set_dir(old_dir); 
        old_pos = next_pos;
        old_dir = next_dir;
    }
}

void Snake::changeDirection(Coord direction)
{
    _tail[0].set_dir(direction);
}

Coord Snake::getHeadCoord()
{
    return _tail[0].get_dir();
}

void Snake::printCoords()
{
    for(auto part : _tail)
    {
        std::cout << part.get_char() << " pos: " << part.get_pos() 
                  << " dir: " << part.get_dir() <<  std::endl;
    }
}

std::vector<Body>& Snake::getBody()
{
    return _tail;
}

void Snake::grow()
{
    Body old_last = _tail.back();
    Coord new_pos = old_last.get_pos() - old_last.get_dir();
    Body new_last = Body(Body::TAIL, new_pos, old_last.get_dir());
    _tail.push_back(new_last); 
}
