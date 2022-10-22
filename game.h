#ifndef GAME_H
#define GAME_H

#include <ncurses.h>
#include <cstring>
#include <string>

using namespace std;
class Game {

  public:

    // game constructor: give the main window dimentions and postion and more.
    Game();

    // destructor: kills the ncursees window 
    ~Game();

    // sets the initial direction on the global player private pair pos
    void move_player(int in);


    // puts the map on the main window
    void print_map(string map_00[11]);

  private: 

    WINDOW *win;

    // gives the dimention to the  main game window
    int main_x, main_y ,x,y , width, height;

    // all map in the game that are going to be printed
    //std::string map_00[11];  //map_01[11]  ,map_o2[11],  map_03[11], map_o4[11], map_05[11];
};


#endif //HEADERFILE_H
