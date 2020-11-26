// main.cpp
#include<iostream>
#include<vector>
#include "Coord.h"
#include "Thing.h"
#include "Random.h"
#include "Map.h"
#include "Food.h"
#include "Air.h"
#include "Border.h"
#include "Body.h"
#include "Snake.h"


/*
 * Thing subclasses
 *    - Border: 
 *        * Corner: +, Wall: horizontal - und vertikal |
 *    - Food: o
 *    - Body:
 *        * Head: @
 *        * Tail: #
*/

int main()
{
    const int size_x = 20;
    const int size_y = 10;
    Map map(size_x, size_y);
 
    // Game builds the map TODO: put this in Game class

    // corners
    map.add(Border(Border::CORNER), Coord(0, 0));
    map.add(Border(Border::CORNER), Coord(0, size_y-1));
    map.add(Border(Border::CORNER), Coord(size_x-1, 0));
    map.add(Border(Border::CORNER), Coord(size_x-1, size_y-1));
    

    // horizontal walls
    for(int x = 1; x < size_x-1; x++)
    {
        // top
        map.add(Border(Border::HORIZONTAL), Coord(x, 0));
        // bottom
        map.add(Border(Border::HORIZONTAL), Coord(x, size_y-1));
    }


    // vertical walls
    for(int y = 1; y < size_y-1; y++)
    {
        // left
        map.add(Border(Border::VERTICAL), Coord(0, y));
        // right
        map.add(Border(Border::VERTICAL), Coord(size_x-1, y));
    }
    
    // put Food at a random position
    auto rand = Random();
    map.add(Food(), rand.get_coord(1, size_x-1, 1, size_y-1));

    // Make a copy of the original map for snake rendering
    Map smap = map;



    // empty map rendering
    std::cout << smap.render();

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


    return 0;
}
