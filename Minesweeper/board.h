#ifndef MINESWEEPER_BOARD_H
#define MINESWEEPER_BOARD_H
#include <array>
#include <vector>


namespace Minesweeper {

    struct Location {
        char row;
        int col;
    };

    enum CellStatus{
        Covered,
        Flagged,
        Uncovered,
    };

    struct Cell {
        bool mine;
        char label;
        CellStatus status;
    };


    struct BoardSize{
        int r, c;
        int totalMines;
    };

    class Board {
    private:
        Cell setCellAtLoc(Location loc);
    public:
        using Row = std::array<Cell, 6>;
        std::vector <Row> cells;
        //std::vector<std::vector<Cell>> cells;


        BoardSize gridSize;

        Board();
        void clear();
        void customBoard(int rows, int cols, int mines);
        void setMine(Location loc);
        void setCellStatus(Location loc);
        std::tuple<int, int> convertLocation(Location loc);
    };
}
#endif //MINESWEEPER_BOARD_H
