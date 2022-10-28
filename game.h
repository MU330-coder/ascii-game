// Copyright 2022 Robot Locomotion Group @ CSAIL. All rights reserved.
// All components of this software are licensed under the GNU License.
// Programmer: Martin Montas, martinmontas1@gmail.com
#ifndef GAME_H_
#define GAME_H_

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
        bool playerCanBeMoved();
        void moveZombie();
        void moveAlien();
        void printMap(std::string name_of_text_file);
        void refreshWindow(WINDOW *win);
        bool playerNearEnemy();

        int in;
 private:
      WINDOW *win;
      int main_x , main_y , x , y , width , height;
      std::pair<int, int> alienPosition[2];
      std::pair<int, int> zombiePosition[2];
      bool theresZombie, theresAlien, enemyNotClose;
};
#endif  // GAME_H_

