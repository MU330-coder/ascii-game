// Copyright 2022 Robot Locomotion Group @ CSAIL. All rights reserved.
// All components of this software are licensed under the GNU License.
// Programmer: Martin Montas, martinmontas1@gmail.com
#include <ncurses.h>
#include "game.h"

bool RUNNING;
void get_dir(Game *g) {
    int in = getch();

    if (in == 'q') {
        RUNNING = false;
    } else {
        g->game_main(in);
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
