// Copyright 2022 Robot Locomotion Group @ CSAIL. All rights reserved.
// All components of this software are licensed under the GNU License.
// Programmer: Martin Montas, martinmontas1@gmail.com
#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "game.hpp"

class Player: private Game {
 public:
        void movePlayerProperly();
        bool playerCanBeMove();
        void movePlayer();
        void mainCharSetterX(int a) { x = a;}
        void mainCharSetterY(int b) { y = b;}
        int  mainCharGetterX() { return x;}
        int  mainCharGetterY() { return y;}
        int in;
 protected:
};

#endif  // PLAYER_HPP_
