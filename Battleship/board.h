#ifndef GRID_H
#define GRID_H
#include <array>
#include <vector>
#include <string>

enum Cell : char{
    X = 'X',
    O = 'O',
    Empty = '.',

    Carrier = '0',
    Battleship = '1',
    Cruiser = '2',
    Submarine = '3',
    Destroyer = '4',
};
const int BOARD_SIZE = 10;
class Board{
public:
    using Row = std::array<Cell, BOARD_SIZE>;
    std::vector<Row> cells;

    Board(){
        cells.resize(BOARD_SIZE);
        for (int r = 0; r < BOARD_SIZE; r++){
            for (int c = 0; c < BOARD_SIZE; c++){
                cells[r][c] = Cell::Empty;
            }
        }
    }

    void setPoint_Board(int x, int y, char c);
    void setShot_Board(int x, int y, Cell ch);

};

#endif