// Game.h

#ifndef GAME_H
#define GAME_H

#include "Map.h"
#include "Snake.h"
#include "Coord.h"
#include "Random.h"
#include "ncurses.h"

#define DEBUG 0

class Game
{
    Random _rand;
    Map _map;
    Snake _snake;
    WINDOW* _main_wnd;
    unsigned int _tick;

public:

    // Constructor
    //
    // Generate a Game with a map of size map_size and start with a
    // snake at snake_position, which starts at direction
    // snake_direction.
    //
    Game(Coord map_size, Coord snake_position, Coord snake_direction);

    // Destructor
    //
    ~Game()
    {
        // close and clean up ncurses
        delwin(_main_wnd);
        endwin();
    }

    // Put the Food method
    //
    // Put Food on the Map at a random position
    void putFood();

    // Put the Food method
    //
    // Put Food on the Map at the given position
    void putFood(Coord pos);

    // Direction method for steering the Snake
    //
    // The Snakes direction is updated with the given direction
    void direct(Coord direction);

    // Game loop method
    //
    // Compute one tick - a single step - of the game progress.
    // Return true, if the snake collided.
    // Return false, if the snake is moving freely.
    //
    bool tick();

    void _printGameOver();
};

#endif // GAME_H
