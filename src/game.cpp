// Copyright 2022 Robot Locomotion Group @ CSAIL. All rights reserved.
// All components of this software are licensed under the GNU License.
// Programmer: Martin Montas, martinmontas1@gmail.com

#include <unistd.h>
#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <utility>
#include "game.hpp"
#include "enemy.hpp"

Game::Game() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    main_y = 4, main_x = 4, width = 124, height = 25, x = 10, y = 8;
    win = newwin(height, width, main_y, main_x);
    keypad(win, true);
    box(win, 0, 0);
    refresh();
    wrefresh(win);
    std::string tmp = "../maps/map00.txt";
    refresh();
    wrefresh(win);
    printMap(tmp);
}

Game::~Game() {
    getch(); endwin();
}
void Game::refreshWindow(WINDOW *win) {
    refresh();
    wrefresh(win);
}

void Game::movePlayerProperly() {
    if (in == 'l') {
        mvwaddch(win, y, x, ' ');
        x++;
    }
    if (in == 'k') {
        mvwaddch(win, y, x, ' ');
        y--;
    }
    if (in == 'j') {
        mvwaddch(win, y, x, ' ');
        y++;
    }
    if (in == 'h') {
        mvwaddch(win, y, x, ' ');
        x--;
    }
    refreshWindow(win);
}

bool Game::playerCanBeMoved() {
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




void Game::movePlayer() {
    if (playerCanBeMoved()) {
        movePlayerProperly();
    }
    char current_char = mvwinch(win, y, x);
    if (current_char == ' ') {
        mvwaddch(win, y, x, '@');
        refreshWindow(win);
    }
}
void Game::gameMain() {
    movePlayer();
}


void Game::printMap(std::string name_of_text_file) {
    std::ifstream file(name_of_text_file);
    std::string str;
    int row        = 0;
    int index      = 0;
    theresEnemy = false;
    // Enemy *enemy = new Enemy();
    while (std::getline(file, str)) {
        for (uint16_t col = 0; col < str.size(); col++) {
            if (str[col] == 'A' || str[col] == 'Z') {
                theresEnemy = true;
                enemyPos[index] = std::make_pair(row, col);
                index++;
            }
        }
        mvwprintw(win, row, 1, "%s", str.c_str());
        refreshWindow(win);
        row++;
        if (row == height) {
            break;
        }
    }
}
