#ifndef GAME_CPP
#define GAME_CPP
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include "game.h"
#include "board.h"
#include "io.h"

using std::vector;
using std::string;

/*struct Shot{
    char col;
    int row;
};

const int NUM_SHIPS = 5;

struct Point{
    char col;
    int row;
    bool direction;
};

struct Ship{
    std::string name;
    int length;
    bool is_sunk;
};*/



class Game{
private:
    const int SHIP_TYPES = 5;

    Board primary;

//int shipCount = NUM_SHIPS;
    //std::vector<std::pair<char, int>> ships;
    /*using Pairs = std::pair<char, int>;
    std::vector<Pairs> points;*/

    /*Ship shipTypes[5] = {{"Carrier", 5},
                         {"Battleship", 4},
                         {"Cruiser", 3},
                         {"Submarine", 3},
                         {"Destroyer", 2}};*/


    //void setShip(Point point, int count);

    //bool gameOver(Shot shot);
    //bool isHit(Shot shot);
    //void setShipPoints(Point point);
    //std::string getShipType(Shot shot);
};

#endif