// Copyright 2022 Robot Locomotion Group @ CSAIL. All rights reserved.
// All components of this software are licensed under the GNU License.
// Programmer: Martin Montas, martinmontas1@gmail.com
#include <ncurses.h>
#include "game.hpp"



bool RUNNING;
void get_dir(Game *g) {
    g->in = getch();

    if (g->in == 'q') {
        RUNNING = false;
    } else {
        g->gameMain();
    }
}
int main() {
    RUNNING = true;
    Game *g = new Game;

    do {
        get_dir(g);
    }while(RUNNING);
    g->~Game();
    return 0;
}
