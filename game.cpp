    // Copyright 2022 Robot Locomotion Group @ CSAIL. All rights reserved.
    // All components of this software are licensed under the GNU License.
    // Programmer: Martin Montas, martinmontas1@gmail.com

    #include "game.h"
    #include <ncurses.h>
    #include <fstream>
    #include <iostream>
    #include <string>
    #include <array>

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
        main_y = 4, main_x = 4, width=124,height= 25, x = 10, y = 8;
        win = newwin(height, width, main_y, main_x);
        keypad(win, true);
        box(win, 0, 0);
        refresh();
        wrefresh(win);
        std::string tmp = "maps/map00.txt";
        refresh();
        wrefresh(win);
        print_map(tmp);
    }

    ////////////////////////////////////
    //
    //     move player
    //
    ////////////////////////////////////
    void Game::move_player(int in) {
        if (in == 'l' && mvwinch(win, y, x + 1) != '#') {
            mvwaddch(win, y, x, ' ');
            refresh();
            wrefresh(win);
            x++;
            if (x >= this->width - 2) {
                x--;
            }
        }
        if (in == 'k' && mvwinch(win, y - 1, x) != '#') {
            mvwaddch(win, y, x, ' ');
            refresh();
            wrefresh(win);
            y--;
            if (y < 1) {
                y++;
            }
        }
        if (in == 'j' && mvwinch(win, y + 1, x) != '#') {
            mvwaddch(win, y, x, ' ');
            refresh();
            wrefresh(win);
            y++;
            if (y > this->height - 2) {
                y--;
            }
        }
        if (in == 'h' && mvwinch(win, y, x - 1) != '#') {
            mvwaddch(win, y, x, ' ');
            refresh();
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
    //       move enemy
    //
    ////////////////////////////////////
    void Game::move_enemy(char enemy_char) {
        /*
            TODO: create logic for making the enemies move
            to the position of the main char when they are near
            like in pacman.
        */
    if (enemy_char = 'Z') {
        enemy_pos_zom[0].second =  enemy_pos_zom[0].second -1;
        mvwaddch(win,enemy_pos_zom[0].first, enemy_pos_zom[0].second - 1,enemy_char);
        refresh();
        wrefresh(win);
    }
    if (enemy_char = 'A') {
        enemy_pos_alien[0].second =  enemy_pos_alien[0].second -1;
        mvwaddch(win,enemy_pos_alien[0].first, enemy_pos_alien[0].second - 1,enemy_char);
        refresh();
        wrefresh(win);
    }
    }
    ////////////////////////////////////
    //
    //      main game funtionality
    //
    ////////////////////////////////////
    void Game::game_main(int in) {
        move_player(in);
        move_enemy('Z');
        

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
        int row       = 0;
        int pos_zom   = 0;
        int pos_alien = 0;
        while (std::getline(file, str)) {
            for (int col = 0; col < str.size(); col++) {
                if ( str[col] == 'A' ) {
                        enemy_pos_alien[pos_alien] = std::make_pair(row,col);
                        pos_alien++;
                }
                if ( str[col] == 'Z' ) {
                        enemy_pos_zom[pos_zom] = std::make_pair(row,col);
                        pos_zom++;
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
