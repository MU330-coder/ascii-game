// Copyright 2022 Robot Locomotion Group @ CSAIL. All rights reserved.
// All components of Drake are licensed under the GNU License.
// Programmer: Martin Montas, martinmontas1@gmail.com
#include <ncurses.h>

#include "game.h"



bool RUNNING;                   // runs the main loop
void get_dir(Game *g) {
    int in = getch();

    // here we take input of the player
    if (in == 'q') {
        RUNNING = false;
    } else {
        // moves the player
        g->move_player(in);
    }
}
int main() {
    // the main loop bool
    RUNNING = true;

    // calls the game and initiates ncurses
    // inits in its constructor
    Game *g = new Game;

    do {
        // this FUNCTION should be should be multi-threaded
        get_dir(g);
    }while(RUNNING);
    g->~Game();
    return 0;
}
