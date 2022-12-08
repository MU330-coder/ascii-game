// reconstructPate/ Copyright 2022 Robot Locomotion Group @ CSAIL.
// All rights reserved.
// All components of this software are licensed under the GNU License.
// Programmer: Martin Montas, martinmontas1@gmail.com
#ifndef ENEMY_HPP_
#define ENEMY_HPP_
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include "game.hpp"
class Enemy: private Game {
 public:
       Enemy();
       std::vector<std::vector<std::pair<int, int>>> bfs();
       std::vector<std::vector<std::pair<int, int>>>
       solve(std::pair <int, int >s);
       std::vector<std::vector<std::pair<int, int>>>
        recons(std::pair<int, int> s, std::pair<int, int> e);
       std::vector<std::pair<int, int>>
       getNeighbours(int qY, int qX);
 private:
       std::queue<int> queueWidth;
       std::queue<int> queueHeight;
       bool reachEnd;
       int rr, cc;
       std::vector <std::vector<bool>> visited;
       std::vector <std::vector<std::pair<int, int>>>  prev;
};

#endif  // ENEMY_HPP_
