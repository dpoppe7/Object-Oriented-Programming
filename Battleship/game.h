#ifndef GAME_H
#define GAME_H
#include <string>
#include <vector>
#include <array>
#include <map>
#include "board.h"

struct POINT {
    int X;
    int Y;
};

struct Coords{
    int c, r, dir;
};

const int SHIP_TYPES = 5;

struct SHIP {
    std::string name;
    int length;
    POINT point[5];
    bool hitFlag[5];
};


enum DIRECTION {HORIZONTAL,VERTICAL};
struct PLACESHIP {
    DIRECTION direction;
    SHIP shipType;
};

class Game{
private:
public:
    int remainingShips = SHIP_TYPES;
    bool gameRunning = false;
    Board primary;
    Board board;

    SHIP ship[SHIP_TYPES];
    int aShip_length;
    PLACESHIP myShip;

    std::multimap<int, int> Shots;
    std::multimap<int, int>::iterator it;

    void LoadShips(){
        ship[0].name = "Carrier"; ship[0].length = 5;
        ship[1].name = "Battleship"; ship[1].length = 4;
        ship[2].name = "Cruiser"; ship[2].length = 3;
        ship[3].name = "Submarine"; ship[3].length = 3;
        ship[4].name = "Destroyer"; ship[4].length = 2;
    }
    Board primaryBoard();
    Board userBoard();

    Coords setInput(std::string input);
    void defineShip(Coords coord, int thisShip);

    void setShips(int thisShip);

    POINT setPoint(std::string input);
    bool checkPoint(POINT point);

    std::string getShipName(POINT point);
    bool existShot(POINT point);
    void saveShot(POINT point);

    void hitShip(POINT point);
    bool ship_isSunk();

    void setHit_myBoard(POINT point);
    void setMiss_myBoard(POINT point);


    bool surrender(std::string input);
    bool win();

    int getTotalTurns();
};

#endif