// Copyright 2022 Robot Locomotion Group @ CSAIL. All rights reserved.
// All components of this software are licensed under the GNU License.
// Programmer: Martin Montas, martinmontas1@gmail.com

#include "game.h"
#include <ncurses.h>
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
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
  printMap(tmp);
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

void Game::moveZombie() {
  if (theresZombie) {
    if (playerNearEnemy()) {
      if (zombiePosition[0].second < x) {
        mvwaddch(win, zombiePosition[0].first , zombiePosition[0].second, ' ');
        mvwaddch(win, zombiePosition[0].first, zombiePosition[0].second + 1, 'Z');
        zombiePosition[0].second = zombiePosition[0].second +1;
        refreshWindow(win);
      }
      if (zombiePosition[0].second > x) {
        mvwaddch(win, zombiePosition[0].first , zombiePosition[0].second, ' ');
        mvwaddch(win, zombiePosition[0].first, zombiePosition[0].second - 1, 'Z');
        zombiePosition[0].second = zombiePosition[0].second -1;
        refreshWindow(win);
      } else {
        // TODO:
        mvwaddch(win, zombiePosition[0].first, zombiePosition[0].second, ' ');
        mvwaddch(win, zombiePosition[0].first, zombiePosition[0].second - 1, 'Z');
        zombiePosition[0].second = zombiePosition[0].second -1;
        refreshWindow(win);
        }
      }
    }
  }


// might need parameters
bool Game::playerNearEnemy() {
  if((abs(zombiePosition[0].first - y) + abs(zombiePosition[0].second - x)) <= 4) {
    return true;
  }
  else {
    return false;
  }

}
void Game::moveAlien() {

  if (theresAlien) {
  alienPosition[0].second = alienPosition[0].second -1;
  mvwaddch(win, alienPosition[0].first, alienPosition[0].second - 1, 'A');
  refreshWindow(win);
  }
}
void Game::gameMain() {
  movePlayer();
  // TODO: work on this two function 
  // that will make the enemies move
  // towards the player.

    moveZombie();
    moveAlien();

}

Game::~Game() {
  getch();
  endwin();
}


void Game::printMap(std::string name_of_text_file) {
  std::ifstream file(name_of_text_file);
  std::string str;
  int row       = 0;
  int pos_zom   = 0;
  int pos_alien = 0;
  theresAlien = false;
  theresZombie = false;
  while (std::getline(file, str)) {
    for (int col = 0; col < str.size(); col++) {
      if ( str[col] == 'A' ) {
        theresAlien = true;
        alienPosition[pos_alien] = std::make_pair(row, col);
        pos_alien++;
      }
      if ( str[col] == 'Z' ) {
        theresZombie = true;
        zombiePosition[pos_zom] = std::make_pair(row, col);
        pos_zom++;
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
