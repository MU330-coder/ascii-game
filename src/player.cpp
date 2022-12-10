// Copyright 2022 Robot Locomotion Group @ CSAIL. All rights reserved.
// All components of this software are licensed under the GNU License.
// Programmer: Martin Montas, martinmontas1@gmail.com
#include "player.hpp"
#include <ncurses.h>



bool Player::playerCanBeMove() {
    // returns true if the given player can 
    // move true the gven path
    //
    if (in == 'l' && mvwinch(win, y, x + 1) != '#') {
        return true;
    }
    if (in == 'k' && mvwinch(win, y - 1, x) != '#') {
        return true;
    }
    if (in == 'j' && mvwinch(win, y + 1, x) != '#') {
        return true;
    }
    if (in == 'h' && mvwinch(win, y, x - 1) != '#') {
        return true;
    } else {
        return false;
    }
}

void Player::movePlayerProperly() {
    // advances the main char position
    // dependent on the in variable
    mvwaddch(win, y, x, ' ');
    if (in == 'l') {
        x++;
    }
    if (in == 'k') {
        y--;
    }
    if (in == 'j') {
        y++;
    }
    if (in == 'h') {
        x--;
    }
    refresh();
    wrefresh(win);
}

void Player::movePlayer() {
    // moves the player to the given place
    if (playerCanBeMove()) {
        movePlayerProperly();
    }
    unsigned int current_char = mvwinch(win, y, x);
     if (current_char == ' ') {
        mvwaddch(win, y, x, '@');
        refresh();
        wrefresh(win);
        }
    }

