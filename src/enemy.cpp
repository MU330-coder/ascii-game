// Copyright 2022 Robot Locomotion Group @ CSAIL. All rights reserved.
// All components of this software are licensed under the GNU License.
// Programmer: Martin Montas, martinmontas1@gmail.com
//
#include "enemy.hpp"
#include "game.hpp"
#include <queue>
#include <vector>
#include <utility>

///////////////////////////////
//
//      playerNearEnemy
//
///////////////////////////////
 bool Enemy::playerNearEnemy() {
    if ((abs(enemyPos[0].first - y) + abs(enemyPos[0].second - x)) <= 4) {
        return true;
    } else {
        return false;
    }
}


///////////////////////////////
//
//      getNeighbours
//
///////////////////////////////
void Enemy::getNeighbours(int qY, int qX) {
    if ((mvwinch(win,qY,qX-1) == ' ') && (qX >= main_x)) {
            neigh[0] = (std::make_pair(qY,qX-1));
        }
    if ((mvwinch(win,qY,qX+1) == ' ') && (qX <= width)) {
            neigh[1] = (std::make_pair(qY,qX+1));
        }
    if ((mvwinch(win,qY-1,qX) == ' ') && (qY <= main_y)) {
            neigh[2] = (std::make_pair(qY-1,qX));
        }
    if ((mvwinch(win,qY+1,qX) == ' ') && (qY <= height)) {
            neigh[3] = (std::make_pair(qY+1,qX));
        }
    }

///////////////////////////////
//
//      solve
//
///////////////////////////////
std::vector<std::vector<std::pair<int, int>>> Enemy::solve(std::pair <int,int> s) {
    reachEnd = false;

    std::vector<std::vector<std::pair<int, int>>>  prev;

    for (int i =0; i< height;i++) {
        for (int j =0; j< width;j++) {
        prev[i][j] = std::make_pair(-1,-1);
        }
    }

    for (int i =0; i< height;i++) {
        for (int j =0; j< width;j++) {
        visited[i][j] = true;
        }
    }
    queueWidth.push(x);
    queueHeight.push(y);

    visited[y][x] = true;

    while(!queueHeight.empty()) {
        int qY = queueHeight.front();
        int qX = queueWidth.front();

        queueHeight.pop();
        queueWidth.pop();

        // should get the neighbours here:
        getNeighbours(qY,qX);
        for (long unsigned int i = 0 ; i< neigh.size();i++) {

            if (!visited[neigh[i].first][neigh[i].second]) {
                queueHeight.push(neigh[i].first);
                queueWidth.push(neigh[i].second);
                visited[neigh[i].first][neigh[i].second] = true;
                prev[neigh[i].first][neigh[i] .second] = std::make_pair(qY,qX); 

            }
        }

    }
    return prev;

}
///////////////////////////////
//
//      reconstructPath
//
///////////////////////////////
void Enemy::reconstructPath(std::pair<int ,int> s, std::pair<int,int> e) {
}


///////////////////////////////
//
//      bfs
//
///////////////////////////////
void Enemy::bfs(std::pair<int,int> s , std::pair<int, int>e) {

    std::vector<std::vector<std::pair<int,int>>> prev = solve(s);

    //int prev = solve(s);
    //return reconstructPath(s,e);
}
