// Copyright 2022 Robot Locomotion Group @ CSAIL. All rights reserved.
// All components of this software are licensed under the GNU License.
// Programmer: Martin Montas, martinmontas1@gmail.com
//
#include "enemy.hpp"
#include <queue>
#include <utility>

extern std::pair <int, int> enemyPos[2];

void Enemy::moveZombie() {
}
bool Enemy::playerNearEnemy() {
    // code a better way to do this

    if ((abs(enemyPos[0].first - y) + abs(enemyPos[0].second - x)) <= 4) {
        return true;
    } else {
        return false;
    }
}


void breadthFirstSearch() {
    // int x_,y_;
    std::queue< std::pair<int, int> > path;
    // path.push({curr.first, curr.second});
    // bool visited[width*height];
    /*
       while (!path.empty()) {
       y_ =  path.front().first;
       x_ =  path.front().second;
       path.pop();
       if (mvwinch(win, y_,x_) != ' ') {
       continue;
       }
    // puth
    path.push({y_+1,x_});
    path.push({y_-1,x_});
    path.push({y_,x_-1});
    path.push({y_,x_+1});
    }
    */
}

void Enemy::moveAlien() {
}
