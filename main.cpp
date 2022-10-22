// Copyright 2022 Robot Locomotion Group @ CSAIL. All rights reserved.
// All components of Drake are licensed under the GNU License.
// Programmer: Martin Montas, martinmontas1@gmail.com
#include <ncurses.h>
#include "game.h"

bool RUNNING;
void get_dir(Game *g) {
    int in = getch();

    if (in == 'q') {
        RUNNING = false;
    } else {
        g->move_player(in);
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
