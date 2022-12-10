// Copyright 2022 Robot Locomotion Group @ CSAIL. All rights reserved.
// All components of this software are licensed under the GNU License.
// Programmer: Martin Montas, martinmontas1@gmail.com

#include <unistd.h>
#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include "player.hpp"
#include "game.hpp"

#define HEALTH_COL 1
#define ARMOR_COL 2
#define AMMO_COL 3
#define RED_COL 4
Game::Game() {
    // initiates all the main curses components
    initscr();
    cbreak();
    noecho();
    if (!has_colors()) {
        endwin();
        printf("Your terminal does not support color\n");
        exit(1);
    }
    // starts the color on the screen
    start_color();   
    init_pair(HEALTH_COL, COLOR_GREEN, COLOR_BLACK);
    init_pair(ARMOR_COL, COLOR_BLUE, COLOR_BLACK);
    init_pair(AMMO_COL, COLOR_YELLOW, COLOR_BLACK);
    init_pair(RED_COL, COLOR_RED, COLOR_BLACK);
    clear();
    x = 2, y = 10;
    curs_set(0);
    main_y = 1, main_x = 1;
    widthHeightSetter(124, 25);
    WINDOW *statWin = newwin(15, 30, 1, 130);
    keypad(statWin, true);
    box(statWin, 0, 0);
    refresh();
    wrefresh(statWin);
    mvwprintw(statWin, 1, 1, "    ---- [STATS] ----");
    wrefresh(statWin);
    wattron(statWin, COLOR_PAIR(HEALTH_COL));
    mvwprintw(statWin, 4, 1, "HEALTH POINTS");
    wattroff(statWin, COLOR_PAIR(HEALTH_COL));
    wrefresh(statWin);
    wattron(statWin, COLOR_PAIR(ARMOR_COL));
    mvwprintw(statWin, 5, 1, "ARMOR POINTS");
    wattroff(statWin, COLOR_PAIR(ARMOR_COL));
    wrefresh(statWin);
    updateHealthPoints(statWin, 180);
    updateArmorPoints(statWin, 100);
    win = newwin(height, width, main_y, main_x);
    keypad(win, true);
    box(win, 0, 0);
    refresh();
    wrefresh(win);
    std::string tmp = "../maps/map00.txt";
    wrefresh(win);
    printMap(tmp);
}

void Game::updateHealthPoints(WINDOW *win, int val) {
    // puts the main health points with the color
    // and the correct position
    wattron(win, COLOR_PAIR(RED_COL));
    mvwprintw(win, 4, 17, "[ %d ]", val);
    wattroff(win, COLOR_PAIR(RED_COL));
    wrefresh(win);
}
void Game::updateArmorPoints(WINDOW *win, int val) {
    // puts the main armor points with the color
    // and the correct position
    wattron(win, COLOR_PAIR(RED_COL));
    mvwprintw(win, 5, 17, "[ %d ]", val);
    wattroff(win, COLOR_PAIR(RED_COL));
    wrefresh(win);
}

Game::~Game() {
    // finishes the mainscreen
    getch();
    endwin();
}
void Game::refreshWindow(WINDOW *win) {
    refresh();
    wrefresh(win);
}

void Game::printMap(std::string name_of_text_file) {
    // prints the maps and all the tells with there are
    // any zombies in it.
    std::ifstream file(name_of_text_file);
    std::string str;
    int row        = 0;
    int index      = 0;
    theresEnemy    = false;
    while (std::getline(file, str)) {
        for (uint16_t col = 0; col < str.size(); col++) {
            if (str[col] == 'A' || str[col] == 'Z') {
                theresEnemy = true;
                enemyCharSetter(row, col, index);
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
