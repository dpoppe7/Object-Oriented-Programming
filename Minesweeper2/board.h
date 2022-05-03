#ifndef MINESWEEPER_BOARD_H
#define MINESWEEPER_BOARD_H
#include <array>
#include <vector>


namespace Minesweeper {

    struct Location {
        int row;
        int col;
    };

    enum class CellStatus{
        Covered,
        Flagged,
        Uncovered,
    };

    struct Cell {
        bool mine;
        int label;
        CellStatus status;
    };


    struct BoardSize{
        int row, col;
    };

    class Board{
    private:

    public:
        using Row = std::array<Cell, 9>;
        std::array<Row, 9> cells;

        BoardSize boardSize;
        Board();
        void resizeBoard(int r, int c);
        bool onBoard(int, int);

         void placeMinesOnBoard(std::vector<Location> mines);
         Board updateBoard(Board board, int numRow, int numCol);
    };
}
#endif //MINESWEEPER_BOARD_H
