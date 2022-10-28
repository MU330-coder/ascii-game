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

        void move_player(int in);

        void game_main(int in);

        void move_enemy(char enemy_char); 

        void print_map(std::string name_of_text_file);

 private:
      WINDOW *win;
      int main_x , main_y , x , y , width , height;
      std::pair<int , int> enemy_pos_alien[2];
      std::pair<int , int> enemy_pos_zom[2];

};
#endif  // GAME_H_

