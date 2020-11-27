// main.cpp
#include<iostream>
#include<vector>
#include "Coord.h"
#include "Thing.h"
#include "Map.h"
#include "Air.h"
#include "Body.h"
#include "Snake.h"
#include "Game.h"


int main()
{
    auto map_size = Coord(20, 10);
    auto snake_pos = Coord(12, 5);
    auto snake_dir = Coord(1, 0);
    Game game(map_size, snake_pos, snake_dir);

    game.tick();
    game.putFood(snake_pos + Coord(2, 0));
    game.tick();
    game.putFood(snake_pos + Coord(6, 0));
    game.putFood(snake_pos + Coord(5, 0));
    game.tick();
    game.tick();
    game.tick();
    game.tick();
    game.direct(Coord(0, -1));
    game.tick();
    std::cout << game.tick() << std::endl;
    std::cout << game.tick() << std::endl;
    std::cout << game.tick() << std::endl;
    game.direct(Coord(-1, 0));
    std::cout << game.tick() << std::endl;
    game.direct(Coord(0, 1));
    std::cout << game.tick() << std::endl;
    game.direct(Coord(1, 0));
    std::cout << game.tick() << std::endl;
/*


    // Initialize Snake with direction LEFT and render
    // TODO: Later define a Direction class, which inherits from Coord?
    Snake snake = Snake(Coord(5, 5), Coord(-1, 0));
    snake.printCoords();
    // put the Snake on the Map
    // TODO: Do we have to put the snake on the Map?
    // Yes, if we can't choose cursor position
    // No, if we can put it on top of the map afterwards
    for(auto part : snake.getBody())
    {
        bool flag = smap.add(part, part.get_pos());
        std::cout << "DBG: smap.add was: " << flag << std::endl;
        std::cout << "DBG: part: " << part.get_char() << part.get_pos()
                  << std::endl;
    }
    std::cout << smap.render();

    // move one step (left)
    snake.move();
    snake.printCoords();
    smap = map;
    for(auto part : snake.getBody()) // put the Snake on the Map
    {
        bool flag = smap.add(part, part.get_pos());
        std::cout << "DBG: smap.add was: " << flag << std::endl;
        std::cout << "DBG: part: " << part.get_char() << part.get_pos()
                  << std::endl;
    }
    std::cout << smap.render();

    // make a turn from left to up
    snake.changeDirection(Coord(0, -1));
    snake.move();
    smap = map;
    for(auto part : snake.getBody()) // put the Snake on the Map
    {
        bool flag = smap.add(part, part.get_pos());
        std::cout << "DBG: smap.add was: " << flag << std::endl;
        std::cout << "DBG: part: " << part.get_char() << part.get_pos()
                  << std::endl;
    }
    std::cout << smap.render();

    // grow and move
    snake.grow();
    snake.move();
    smap = map;
    for(auto part : snake.getBody()) // put the Snake on the Map
    {
        bool flag = smap.add(part, part.get_pos());
        std::cout << "DBG: smap.add was: " << flag << std::endl;
        std::cout << "DBG: part: " << part.get_char() << part.get_pos()
                  << std::endl;
    }
    std::cout << smap.render();
*/

    return 0;
}
