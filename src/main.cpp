// Copyright 2022 Robot Locomotion Group @ CSAIL. All rights reserved.
// All components of this software are licensed under the GNU License.
// Programmer: Martin Montas, martinmontas1@gmail.com
#include <ncurses.h>
#include "game.hpp"
#include "enemy.hpp"
#include "player.hpp"

bool RUNNING;
void moveMainChar() {
    Player  *p = new Player;
    p->in = getch();
    if (p->in == 'q') {
        RUNNING = false;
    } else {
        p->movePlayer();
    }
}
/*
void moveEnemyChar() {
    Enemy   *e = new Enemy;
    //auto path= e->bfs();
}
*/
int main() {
    RUNNING = true;
    Game *g =  new Game;
    do {
        moveMainChar();
        // moveEnemyChar();
        }while(RUNNING);
    g->~Game();
    return 0;
}
