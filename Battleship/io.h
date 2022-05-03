#ifndef P2_IO_H
#define P2_IO_H
#include <string>
#include "board.h"

void printBoard(Board board);

std::string getInput();

std::string getShot();

void printHit(std::string shipName, std::string point, bool sunk);
void printMiss(std::string point);

void printLost();
void printYouWin(int turns);

#endif //P2_IO_H
