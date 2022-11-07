// Copyright 2022 Robot Locomotion Group @ CSAIL. All rights reserved.
// All components of this software are licensed under the GNU License.
// Programmer: Martin Montas, martinmontas1@gmail.com
#ifndef GAME_HPP_
#define GAME_HPP_

#include <ncurses.h>
#include <string>
#include <utility>

class Game {
 public:
        Game();
        ~Game();
        void movePlayer();
        void gameMain();
        void movePlayerProperly();
        void printMap(std::string name_of_text_file);
        void refreshWindow(WINDOW *win);
        void setterMain();


        bool playerCanBeMoved();
        int in;
 protected:
        std::pair <int, int> enemyPos[2];
        WINDOW *win;
        int main_x , main_y, x, y , width, height;
        bool theresEnemy;
        char downString[25];
};
#endif   // GAME_HPP_
