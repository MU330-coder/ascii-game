#ifndef _ENEMY_H_
#define _ENEMY_H_
  
#include "game.hpp"
#include <utility>
#include <iostream>

using namespace std;
class Enemy: private Game{
    public:
        void moveZombie();
        void moveAlien();
        bool mainDownPos();
        bool playerNearEnemy();

        void setEnemyPos(int row,int col, int index); 
        std::pair<int, int> getEnemyPos(int index);
 private:
        std::pair<int, int> enemyPos[1];



};


#endif  //_ENEMY_H_
