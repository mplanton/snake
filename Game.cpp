// Game.cpp

#include "Game.h"
#include "Border.h"
#include "Food.h"

/*
 * Thing subclasses for Map and Snake classes
 *    - Border: 
 *        * Corner: +, Wall: horizontal - und vertikal |
 *    - Food: o
 *    - Body:
 *        * Head: @
 *        * Tail: #
*/

Game::Game(Coord map_size, Coord snake_position, Coord snake_direction) :
    _rand(), _map(map_size), _snake(snake_position, snake_direction)
{
    // TODO: check map and snake parameters!!!

    // build basic map

    // corners
    _map.add(Border(Border::CORNER), Coord(0, 0));
    _map.add(Border(Border::CORNER), Coord(0, _map.get_size_y()-1));
    _map.add(Border(Border::CORNER), Coord(_map.get_size_x()-1, 0));
    _map.add(Border(Border::CORNER), Coord(_map.get_size_x()-1,
                                           _map.get_size_y()-1));

    // horizontal walls
    for(int x = 1; x < _map.get_size_x()-1; x++)
    {
        // top
        _map.add(Border(Border::HORIZONTAL), Coord(x, 0));
        // bottom
        _map.add(Border(Border::HORIZONTAL), Coord(x, _map.get_size_y()-1));
    }

    // vertical walls
    for(int y = 1; y < _map.get_size_y()-1; y++)
    {
        // left
        _map.add(Border(Border::VERTICAL), Coord(0, y));
        // right
        _map.add(Border(Border::VERTICAL), Coord(_map.get_size_x()-1, y));
    }

    // TODO: put food at random position? or later? Do this in main?
}

void Game::putFood()
{
    // Put food on a random position.
    // But check, if there is something else!
    Food food = Food();

    // flag for finding a valid coordinate
    bool good_coord;
    Coord pos;
    do
    {
        good_coord = true;
        pos = _rand.get_coord(1, _map.get_size_x()-1,
                              1, _map.get_size_y()-1);
#if DEBUG
        std::cout << "DBG: Game::putFood(): rand_pos " << pos
                  << " tried." << std::endl;
#endif
        // check Snake
        for(auto part : _snake.getBody())
        {
            if(pos == part.get_pos())
            {
                good_coord = false;
                break;
            }
        }
        if(good_coord == true)
        {
            // put Food at the random position
            good_coord = _map.add(food, pos);
        }
    } while(good_coord == false);
}

void Game::putFood(Coord pos)
{
    // TODO: safety checks
    _map.add(Food(), pos);
}

void Game::direct(Coord direction)
{
    auto s_dir = _snake.getHeadDir();

    // check: cant go opposite direction
    if(direction == -s_dir)
        return;

    _snake.changeDirection(direction);
}

bool Game::tick()
{
    _snake.move();

    // check if the snake eats or collides
    Coord head_pos = _snake.getHeadCoord();
    auto thing = _map.get(head_pos);
    auto type = thing.get_type();

    // found food
    if(type == Thing::FOOD)
    {
        // eat and grow
        _map.remove(head_pos);
        _snake.grow();
#if DEBUG
        std::cout << "found food" << std::endl;
#endif
    }
    else if(type == Thing::BORDER)
    {
        // wall collision
#if DEBUG
        std::cout << "wall collision" << std::endl;
#endif
        return false;
    }

    // Make a copy of the original map for snake rendering
    Map smap = _map;
#if DEBUG
    _snake.printCoords(); //DBG
#endif

    // render the Snake
    // and do self collision detection
    auto parts = _snake.getBody();
    for(unsigned int i = 0; i < parts.size(); i++)
    {
        auto part = parts[i];
        auto p_pos = part.get_pos();

        if((i != 0) && (head_pos == p_pos))
        {
            // self collision
#if DEBUG
            std::cout << "self collision" << std::endl;
#endif
            return false;
        }
        bool flag = smap.add(part, p_pos);
#if DEBUG
        std::cout << "DBG: Game::tick(): smap.add was: " << flag << std::endl;
        std::cout << "DBG:  Game::tick():part: " << part.get_char() << part.get_pos()
                  << std::endl;
#endif
    }
    std::cout << smap.render();

    // TODO: ?? wait for the rest of the frame ??

    return true;
}
