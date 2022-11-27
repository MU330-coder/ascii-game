// Copyright 2022 Robot Locomotion Group @ CSAIL. All rights reserved.
// All components of this software are licensed under the GNU License.
// Programmer: Martin Montas, martinmontas1@gmail.com
#ifndef ENEMY_HPP_
#define ENEMY_HPP_
#include <utility>
#include <iostream>
#include "game.hpp"
#include <queue>
#include <utility>

class Enemy: private Game {
 public:
        void bfs();
        bool playerNearEnemy();
        void bfs(std::pair<int,int> s , std::pair<int, int>e);
        std::vector<std::vector<std::pair<int, int>>>   solve(std::pair <int ,int >s); 
        void reconstructPath(std::pair<int ,int> s, std::pair<int,int> e); 
        void exploreNeighbours(int qY,int qX,int dc[4],int dr[4]);
        bool canFindNeighbour();
        void getNeighbours(int qY,int qX);
 private:
        std::pair<int,int> node;
        std::queue<int> queueWidth;
        std::queue<int> queueHeight;
        bool reachEnd;
        int rr,cc;
        std::vector<std::pair<int,int>> neigh;
        std::vector <std::vector<bool>> visited;
        
        

};


#endif  // ENEMY_HPP_
