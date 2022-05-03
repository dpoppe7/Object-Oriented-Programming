#ifndef BOARD_CPP
#define BOARD_CPP

#include "board.h"

void Board::setPoint_Board(int r, int c, char ch){
    if (ch == Cell::Carrier) cells[r][c] = Cell::Carrier;
    if (ch == Cell::Battleship) cells[r][c] = Cell::Battleship;
    if (ch == Cell::Cruiser) cells[r][c] = Cell::Cruiser;
    if (ch == Cell::Submarine) cells[r][c] = Cell::Submarine;
    if (ch == Cell::Destroyer) cells[r][c] = Cell::Destroyer;
}

void Board::setShot_Board(int r, int c, Cell ch){
    cells[r][c] = ch;
}

#endif