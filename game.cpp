// Copyright 2022 Robot Locomotion Group @ CSAIL. All rights reserved.
// All components of Drake are licensed under the GNU License.
// Programmer: Martin Montas, martinmontas1@gmail.com

#include "game.h"
#include <ncurses.h>
#include <fstream>
#include <iostream>
#include <string>

///////////////////////////////////////////////////////
//
//      print the map of the along with the
//      enemies
//
///////////////////////////////////////////////////////
Game::Game() {
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
        mvwaddch(win, y, x, ' ');
        wrefresh(win);
        y++;
        if (y > this->height -2) {
            y--; }
    }
    if (in == 'h') {
        mvwaddch(win, y, x, ' ');
        wrefresh(win);
        x--;
        if (x < 1)
            x++;
    }
    mvwaddch(win, y, x, '@');
    wrefresh(win);
}

///////////////////////////////////////////////////////
//
//      Game Destructor
//
///////////////////////////////////////////////////////
Game::~Game() {
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
    std::ifstream stream(name_of_text_file);
    std::string line;

    while (stream) {
    getline(stream , line);
    if (stream) {
        mvwprintw(win, 0, 1, "%s", line.c_str());
      }
    }
  }
