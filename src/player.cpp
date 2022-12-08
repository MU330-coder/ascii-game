// Copyright 2022 Robot Locomotion Group @ CSAIL. All rights reserved.
// All components of this software are licensed under the GNU License.
// Programmer: Martin Montas, martinmontas1@gmail.com
#include "player.hpp"
#include <ncurses.h>
///////////////////////////////
//
//      constructor
//
///////////////////////////////
Player::Player() {
}

///////////////////////////////
//
//      movePlayerProperly
//
///////////////////////////////
void Player::movePlayerProperly() {
    int y_ = mainCharGetterY();
    int x_ = mainCharGetterX();
    if (in == 'l') {
        mvwaddch(win, y_, x_, '.');
        x_++;
        mainCharSetterX(x_);
    }
    if (in == 'k') {
        mvwaddch(win, y_, x_, '.');
        y_--;
        mainCharSetterY(y_);
    }
    if (in == 'j') {
        mvwaddch(win, y_, x_, '.');
        y_++;
        mainCharSetterY(y_);
    }
    if (in == 'h') {
        mvwaddch(win, y_, x_, '.');
        x_--;
        mainCharSetterX(x_);
    }
    refresh();
    wrefresh(win);
}

///////////////////////////////
//
//      playerCanBeMove
//
///////////////////////////////
bool Player::playerCanBeMove() {
    int x_ = mainCharGetterX();
    int y_ = mainCharGetterY();
    if (in == 'l' && mvwinch(win, y_, x_ + 1) != '#') {
        return true;
    }
    if (in == 'k' && mvwinch(win, y_ - 1, x_) != '#') {
        return true;
    }
    if (in == 'j' && mvwinch(win, y_ + 1, x_) != '#') {
        return true;
    }
    if (in == 'h' && mvwinch(win, y_, x_ - 1) != '#') {
        return true;
    } else {
        return false;
    }
}

///////////////////////////////
//
//      movePlayer
//
///////////////////////////////
void Player::movePlayer() {
    if (playerCanBeMove()) {
        movePlayerProperly();
    }
    int x_ = mainCharGetterX();
    int y_ = mainCharGetterY();
    char current_char = mvwinch(win, y_, x_);
    if (current_char == '.') {
        mvwaddch(win, y_, x_, '@');
        refresh();
        wrefresh(win);
    }
}
