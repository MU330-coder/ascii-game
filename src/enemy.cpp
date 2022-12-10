// Copyright 2022 Robot Locomotion Group @ CSAIL. All rights reserved.
// All components of this software are licensed under the GNU License.
// Programmer: Martin Montas, martinmontas1@gmail.com
//
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include "enemy.hpp"
#include "game.hpp"

std::vector<std::pair<int, int>>  Enemy::getNeighbours(int qY, int qX) {
    // gets all the current neighbours adjent to the
    // position given and returns a vector of pairs
    // with each position
    std::vector<std::pair<int, int>> neighbours;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, 1 , -1};
    for (int i =0 ; i < 4; i++) {
        rr = qY + dr[i];
        cc =  qX + dc[i];
        if (rr < 0 || cc < 0) {continue;}
        if (rr >= height || cc >= width) {continue;}
        if (visited.at(rr).at(cc)) {continue;}
        if (mvwinch(win, rr, cc) == '#') {continue;}
        neighbours.push_back(std::make_pair(rr, cc));
    }
    return neighbours;
}
std::vector<std::vector<std::pair<int, int>>>
Enemy::solve(std::pair <int, int> s) {
    // does the heavy lifting of the bfs algo 
    // returns an vector of vector with the correct 
    // algo position

    reachEnd = false;
    for (int i =0; i< height; i++) {
        std::vector<std::pair<int, int>> tmpVec;
        for (int j =0; j< width; j++) {
            tmpVec.push_back(std::make_pair(-1, -1));
        }
        prev.push_back(tmpVec);
    }
    for (int k =0; k< height; k++) {
        std::vector<bool> tmpBoolVec;
        for (int o =0; o< width; o++) {
            tmpBoolVec.push_back(false);
        }
        visited.push_back(tmpBoolVec);
    }
    std::pair<int, int> enem = enemyCharGetter(0);
    queueWidth.push(enem.second);
    queueHeight.push(enem.first);
    visited.at(enem.first).at(enem.second) = true;
    while (!queueHeight.empty()) {
        int qY = queueHeight.front();
        int qX = queueWidth.front();

        if ((qY ==  y)  && (qX == x)) {
            reachEnd = true;
            break;
        }
        queueHeight.pop();
        queueWidth.pop();
        std::vector<std::pair<int, int>> nei =  getNeighbours(qY, qX);
        for (uint16_t i = 0; i< nei.size(); i++) {
        if (!visited.at(nei[i].first).at(nei[i].second)) {
            queueHeight.push(nei[i].first);
            queueWidth.push(nei[i].second);
            visited.at(nei[i].first).at(nei[i].second) = true;
            prev.at(nei[i].first).at(nei[i].second) = std::make_pair(qY, qX);
            }
        }
        nei.clear();
    }
    return prev;
}
std::vector<std::vector<std::pair<int, int>>>
Enemy::recons(std::pair<int, int> s, std::pair<int, int> e) {
    std::vector<std::vector<std::pair<int, int>>> path;
    for (int i =height - 1; i>= 0; i--) {
        for (int j =width- 1; j>= 0; j--) {
            if (prev[i][j].first == -1 && prev[i][j].second == -1) {
                continue;
            } else {
                // path[i][j].push(std::make_pair(rev[i][j].first,prev[i][j].second));
            }
        }
    }
    // int x = mainCharGetterX();
    // int y = mainCharGetterY();
    // std::reverse(path.begin(), path.end());
    /*
    if (path[0][0].first  == y && path[0][0].second == x) {
        return path;
    } */
    return path;
}

std::vector<std::vector<std::pair<int, int>>>  Enemy::bfs() {
    std::pair <int, int> s = enemyCharGetter(0);
    // int y = mainCharGetterY();
    // int x = mainCharGetterX();
    std::pair<int, int> e = std::make_pair(y, x);
    auto prev = solve(s);
    // auto path = reconstructPath(s,e,prev);
    return prev;
}
