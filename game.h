// Copyright 2022 Robot Locomotion Group @ CSAIL. All rights reserved.
// All components of Drake are licensed under the GNU License.
// Programmer: Martin Montas, martinmontas1@gmail.com
#ifndef GAME_H_
#define GAME_H_

#include <ncurses.h>
#include <cstring>
#include <string>

class Game {
 public:
        // game constructor: give the main window
        // dimentions and postion and more.
        Game();

        // destructor: kills the ncursees window
        ~Game();

        // sets the initial direction on the global
        // player private pair pos
        void move_player(int in);


        // puts the map on the main window
        void print_map(string map_00[11]);
 private:
      WINDOW *win;
      // gives the dimention to the  main game window
      int main_x , main_y , x , y , width , height;
};
#endif  // GAME_H_

