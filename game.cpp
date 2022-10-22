// Copyright 2022 Robot Locomotion Group @ CSAIL. All rights reserved.
// All components of Drake are licensed under the GNU License.
// Programmer: Martin Montas, martinmontas1@gmail.com
#include <iostream>
#include <ncurses.h>
#include <cstring>
#include <string>
#include "game.h"
#include <fstream>
///////////////////////////////////////////////////////
//
//      print the map of the along with the
//      enemies
//
///////////////////////////////////////////////////////
Game::Game() {
    // this is the contructor that initializes the ncurses screen and
    // the playing window
    initscr();
    cbreak();
    noecho();

    width = 124;
    height = 25;
    main_y = 4, main_x = 4;
    win = newwin(height, width, main_y, main_x);
    x = 10, y = 10;
    keypad(win, true);
    box(win, 0, 0);
    refresh();
    wrefresh(win);
    std::string tmp = "maps/map00.txt";
    print_map(tmp);
}

///////////////////////////////////////////////////////
//
//      print the map of the along with the
//      enemies
//
///////////////////////////////////////////////////////
void Game::move_player(int in) {
    if (in == 'l') {
        /* goes to the right */
        mvwaddch(win, y, x, ' ');
        wrefresh(win);
        x++;
        if (x >= this->width -2) {
            x--;
        }
    }
    if (in == 'k') {
        /* goes to the up */
        mvwaddch(win, y, x, ' ');
        wrefresh(win);
        y--;
        if (y < 1) {
            y++;
        }
    }
    if (in == 'j') {
        /* goes to the down */
        mvwaddch(win, y, x, ' ');
        wrefresh(win);
        y++;
        if (y > this->height -2) {
            y--; }
    }
    if (in == 'h') {
        /* goes to the left */
        mvwaddch(win, y, x, ' ');
        wrefresh(win);
        x--;
        if (x < 1)
            x++;
    }
    /* moves to the player
     * char to the correct place */
    mvwaddch(win, y, x, '@');
    wrefresh(win);
}

///////////////////////////////////////////////////////
//
//      Game Destructor
//
///////////////////////////////////////////////////////
Game::~Game() {
    // GAME OVER!!!
    getch();
    endwin();
}

///////////////////////////////////////////////////////
//
//      print the map of the along with the
//      enemies
//
///////////////////////////////////////////////////////
void Game::print_map(std::string name_of_text_file) {
    // int ind = 0;
    // this loop starts at the given corner where the x coodinate is
    // and continues  until width of the screen

    std::ifstream stream(name_of_text_file);
    std::string line;

    while (stream) {
    getline(stream , line);
    if (stream) {
        // streams when used in a boolean context are
        // converted to a type that is usable in that context.
        // If the stream is in a good state the object returned can
        // be used as true

        // Only write to cout if the getline did not fail.
        mvwprintw(win, 0, 1, "%s", line.c_str());
      }
    }
  }
