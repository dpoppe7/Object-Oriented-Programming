#ifndef MINESWEEPER_IO_H
#define MINESWEEPER_IO_H
#include "board.h"
#include <string>
#include <vector>

namespace Minesweeper {
    enum GameResult {
        Win,
        Lose,
    };

    enum Command{
        Uncover,
        Mark,
    };

    struct Move {
        Command com;
        Location loc;
    };

    class IO {
    private:
        Location readColRow();

    public:
        std::vector<int> customValues;

        char readSign();
        std::vector <Location> getMines();
        std::vector <Location> getMineLocations();
        std::vector <int> getCustomGrid();


        void getMove();
        void reportMove(Move move);

        void printUncovered(Board board);

        char showCellLabel(Board board, int r, int c);
        void printBoard(Board board);
};

}

#endif //MINESWEEPER_IO_H
