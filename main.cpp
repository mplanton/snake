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
    Food a;

    std::cout << " a char: " << a.get_char() << std::endl;

//    Food b;
//    Map map(10, 5);
//    map.add(a, Coord(0, 0));
//    map.add(b, Coord(4, 3));
//    map.add(Food(), Coord(9, 4));
//    map.add(Food(), Coord(0, 4));
//    map.add(Body(Body::HEAD), Coord(3, 3));
//    map.add(Body(Body::TAIL), Coord(3, 4));
//
//    map.add(Border(Border::HORIZONTAL), Coord(2, 3));
//    map.add(Border(Border::VERTICAL), Coord(0, 1));
//    map.add(Border(Border::CORNER), Coord(0, 2));

//    Map map(40, 20);
//    auto size = map.get_size();
//    // Now put random things into the map
//    auto n_things = 15;
//    for(int i = 0; i < n_things; i++)
//    {
//        auto x = rand.get_int(0, size.get_x());
//        auto y = rand.get_int(0, size.get_y());
//        auto rand_pos = Coord(x, y);
//
//        auto c = rand.get_char('a', 'z');
//        auto rand_thing = Thing(c);
//
//        map.add(rand_thing, rand_pos);
//    }
        
    const int size_x = 20;
    const int size_y = 10;
    Map map(size_x, size_y);
    Snake::Action action;
 
    // TODO: Game must build the map

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

    std::cout << map.render();

    Coord aa = Coord(1, 2);
    Coord bb = Coord(1, 1);
    std::cout << "DBG: aa: " << aa << " bb: " << bb << std::endl;
    std::cout << "aa + bb: " << aa+bb << " aa - bb: " << aa-bb << std::endl;

    // TODO: Later define a Direction class, which inherits from Coord
    //Snake snake(Coord(5, 5), Coord(-1, 0));

    //std::cout << map.render(&snake);

    //snake.move(Snake::UP);

    //std::cout << map.render(&snake);

    return 0;
}
