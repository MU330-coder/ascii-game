// Copyright 2022 Robot Locomotion Group @ CSAIL. All rights reserved.
// All components of this software are licensed under the GNU License.
// Programmer: Martin Montas, martinmontas1@gmail.com
#ifndef ENEMY_HPP_
#define ENEMY_HPP_
#include <utility>
#include <iostream>
#include "game.hpp"

class Enemy: private Game{
 public:
        void moveZombie();
        void moveAlien();
        bool mainDownPos();
        bool playerNearEnemy();

        void setEnemyPos(int row, int col, int index);
        std::pair<int, int> getEnemyPos(int index);
};


#endif   // ENEMY_HPP_
