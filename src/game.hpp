// Copyright 2022 Robot Locomotion Group @ CSAIL. All rights reserved.
// All components of this software are licensed under the GNU License.
// Programmer: Martin Montas, martinmontas1@gmail.com
#ifndef GAME_HPP_
#define GAME_HPP_
#include <ncurses.h>
#include <string>
#include <utility>
class Game  {
 public:
        Game();
        ~Game();
        void gameMain();
        void printMap(std::string name_of_text_file);
        void refreshWindow(WINDOW *win);
        bool playerCanBeMove();
        int in;
        int setInitWindow();
        std::pair<int, int> enemyCharGetter(int index) {
               return enemyPos[index];
               }
        void enemyCharSetter(int y, int x, int index) {
               enemyPos[index] = std::make_pair(y, x);
               }

        void widthHeightSetter(int w, int h) {width = w, height = h;}
        void updateHealthPoints(WINDOW *win, int val);
        void updateArmorPoints(WINDOW *win, int val);
 protected:
        WINDOW *win;
        int x, y;
        bool theresEnemy;
        int main_x, main_y, width , height, rr, cc;
        bool theresZombie, theresAlien, enemyNotClose;
        char downString[25];

 private:
        std::pair <int, int>enemyPos[2];
};
#endif  // GAME_HPP_
