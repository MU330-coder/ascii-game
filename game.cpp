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
  main_y = 4, main_x = 4, width = 124, height = 25, x = 10, y = 8;
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
//    refreshWindow
//
////////////////////////////////////
void Game::refreshWindow(WINDOW *win) {
  refresh();
  wrefresh(win);
}

////////////////////////////////////
//
//    movePlayerToSpace
//
////////////////////////////////////
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
  }
  refreshWindow(win);
}

////////////////////////////////////
//
//   playerCanBeMoved
//
////////////////////////////////////
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


////////////////////////////////////
//
//     move player
//
////////////////////////////////////
void Game::movePlayer() {
  if (playerCanBeMoved()) {
    movePlayerProperly();
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
void Game::moveEnemy(char enemy_char) {
  /*
          refactor the code to be less repetitive
          TODO:
          
          try to create a method for each
          type of enemy that moves each of them
              
  */
  if (enemy_char = 'Z') {
  enemy_pos_zom[0].second = enemy_pos_zom[0].second -1;
  mvwaddch(win, enemy_pos_zom[0].first, enemy_pos_zom[0].second - 1, enemy_char);
  refresh();
  wrefresh(win);
  }
  if (enemy_char = 'A') {
  enemy_pos_alien[0].second = enemy_pos_alien[0].second -1;
  mvwaddch(win, enemy_pos_alien[0].first, enemy_pos_alien[0].second - 1, enemy_char);
  refresh();
  wrefresh(win);
  }
}
////////////////////////////////////
//
//      main game funtionality
//
////////////////////////////////////
void Game::game_main() {
  move_player();
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
void Game::printMap(std::string name_of_text_file) {
  std::ifstream file(name_of_text_file);
  std::string str;
  int row       = 0;
  int pos_zom   = 0;
  int pos_alien = 0;
  while (std::getline(file, str)) {
    for (int col = 0; col < str.size(); col++) {
      if ( str[col] == 'A' ) {
        enemy_pos_alien[pos_alien] = std::make_pair(row, col);
        pos_alien++;
      }
      if ( str[col] == 'Z' ) {
        enemy_pos_zom[pos_zom] = std::make_pair(row, col);
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
