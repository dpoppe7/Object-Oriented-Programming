#ifndef GRID_H
#define GRID_H
#include <array>
#include <vector>
#include <string>

enum Cell : char{
    X = 'X',
    O = 'O',
    Empty = '.',
};

class Board{
private:
public:

    using Row = std::array<Cell, 10>;
    std::vector<Row> cells;

    Board(){
        cells.resize(10);
        for (int r = 0; r < 10; r++){
            for (int c = 0; c < 10; c++){
                cells[r][c] = Cell::Empty;
            }
        }
    }


    //void setPoint_Board(int x, int y, char thisShip);

    //void setShip(PLACESHIP myShip, int thisShip);
};

#endif