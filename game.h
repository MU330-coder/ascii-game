// Copyright 2022 Robot Locomotion Group @ CSAIL. All rights reserved.
// All components of Drake are licensed under the GNU License.
// Programmer: Martin Montas, martinmontas1@gmail.com
#ifndef GAME_H_
#define GAME_H_

#include <ncurses.h>
#include <string>

class Game {
 public:
        Game();

        ~Game();

        void move_player(int in);


        void print_map(std::string name_of_text_file);
 private:
      WINDOW *win;
      int main_x , main_y , x , y , width , height;
};
#endif  // GAME_H_

