// main.cpp
#include <ncurses.h>
#include "Coord.h"
#include "Game.h"
#include "unistd.h"

int main()
{
    auto map_size = Coord(20, 10);
    auto snake_pos = Coord(12, 5);
    auto snake_dir = Coord(1, 0);
    Game game(map_size, snake_pos, snake_dir);

    bool collided = false;
    bool quit = false;

    while(!collided)
    {
        switch(getch())
        {
            case 'q':
                quit = true;
                break;
            case 'a':
                // left
                game.direct(Coord(-1, 0));
                break;
            case 'd':
                // right
                game.direct(Coord(1, 0));
                break;
            case 'w':
                // up
                game.direct(Coord(0, -1));
                break;
            case 's':
                // down
                game.direct(Coord(0, 1));
                break;
            default:
                break;
        }

        if(quit)
            break;

        collided = game.tick();

        if(collided)
        {
            int in_char = 0;
            while(true)
            {
                in_char = getch();
                if(in_char == 'q' || in_char == ' ')
                    return 0;
                usleep(200000);
            }
        }
    }


    return 0;
}
