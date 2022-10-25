// Copyright 2022 Robot Locomotion Group @ CSAIL. All rights reserved.
// All components of this software are licensed under the GNU License.
// Programmer: Martin Montas, martinmontas1@gmail.com

#include "game.h"
#include <ncurses.h>
#include <fstream>
#include <thread>
#include <iostream>
#include <string>

/////////////////////////////////////
//
//     game
//
/////////////////////////////////////
Game::Game() {
    initscr();
    cbreak();
    noecho();

    curs_set(0);
    width = 124;
    height = 25;
    main_y = 4, main_x = 4;
    win = newwin(height, width, main_y, main_x);
    x = 10, y = 8;
    keypad(win, true);
    box(win, 0, 0);
    refresh();
    wrefresh(win);
    std::string tmp = "maps/map00.txt";
    print_map(tmp);
    refresh();
    wrefresh(win);
}


////////////////////////////////////
//
//     move player
//
////////////////////////////////////
void Game::move_player(int in) {
    if (in == 'l' && mvwinch(win, y, x + 1) != '#') {
        mvwaddch(win, y, x, ' ');
        wrefresh(win);
        x++;
        if (x >= this->width - 2) {
            x--;
        }
    }
    if (in == 'k' && mvwinch(win, y - 1, x) != '#') {
        mvwaddch(win, y, x, ' ');
        wrefresh(win);
        y--;
        if (y < 1) {
            y++;
        }
    }
    if (in == 'j' && mvwinch(win, y + 1, x) != '#') {
        mvwaddch(win, y, x, ' ');
        wrefresh(win);
        y++;
        if (y > this->height - 2) {
            y--;
        }
    }
    if (in == 'h' && mvwinch(win, y, x - 1) != '#') {
        mvwaddch(win, y, x, ' ');
        wrefresh(win);
        x--;
        if (x < 1) {
            x++;
        }
    }
    char current_char = mvwinch(win, y, x);
    if (current_char == ' ') {
        mvwaddch(win, y, x, '@');
        refresh();
        wrefresh(win);
    }
}

////////////////////////////////////
//
//      thread: move enemy
//
////////////////////////////////////
void Game::move_enemy() {
    // TODO(m. montas) DO THIS NEXT:
}
////////////////////////////////////
//
//      main game funtionality
//
////////////////////////////////////
void Game::game_main(int in) {
    // std::thread enemy_thread(move_enemy);
    // enemy_thread.join();
    move_player(in);
}

////////////////////////////////////
//
//      Game Destructor
//
////////////////////////////////////
Game::~Game() {
    getch();
    endwin();
}

////////////////////////////////////
//
//     print map
//
////////////////////////////////////
void Game::print_map(std::string name_of_text_file) {
    std::ifstream file(name_of_text_file);
    std::string str;
    int row = 0;
    int enemy_count = 0;
    int pos = 0;
    while (std::getline(file, str)) {
        for (int col = 0; col < str.size(); col++) {
            if ((str[col] == 'A') || (str[col] == 'Z')) {
                    // to keep with the ncurses convention  I will be using
                    // the (y,x) on the // position of the pairs.
                    enemy_pos[pos] = std::make_pair(row , col);
                    pos++;
            }
        }

        mvwprintw(win, row, 1, "%s", str.c_str());
        refresh();
        wrefresh(win);
        row++;
        if (row == height) {
            break;
        }
    }
}

