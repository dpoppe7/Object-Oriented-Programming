#ifndef P2_IO_H
#define P2_IO_H
#include <string>
#include "board.h"



void printBoard(Board board);

std::string getInput();

std::string getShot();



//struct Point getPoints(struct Point& point);

//Optional to check ships
//void printShipPoints(std::vector<std::pair<char, int>> ships);

//void printBoard(Board board);
//void printIsOver();

//void printHit(Shot shot, std::string name);
//void printMiss();

//struct Shot getShot(struct Shot& shot);
#endif //P2_IO_H
