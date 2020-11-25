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
        
    Map map(20, 10);
    Snake::Action action;
 
    // TODO: Game must build the map

    std::cout << map.render();

    Snake snake(Coord(5, 5), Snake::DOWN);

    std::cout << map.render(&snake);

    snake.move(Snake::UP);

    std::cout << map.render(&snake);

    return 0;
}
