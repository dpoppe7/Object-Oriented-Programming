#ifndef MINESWEEPER_IO_H
#define MINESWEEPER_IO_H
#include "board.h"
#include <string>
#include <vector>

namespace Minesweeper {

    enum class GameResult {
        Win,
        Lose,
    };

    enum class Command{
        Uncover,
        Mark,
        Sweep,
    };

    struct Move {
        Command comm;
        Location loc;
    };

    struct gameParameters{
        int row, col, mines;
        std::vector<Location> mineLocations;
    };

    class IO{
    public:

        void printUncovered(Board board);

        gameParameters gameParams;
        Move move;
        GameResult gameResult;

        char cellChar(Board board, int r, int c);
        void printBoard(Board board, bool);

        char readSign();
        gameParameters getGameParameters();

        std::tuple<char, int> readALoc();
        std::tuple<int, int> convertLoc_int(char c, int r);

        Location getLocation();

        void getMineLocations(int numMines);
        void randomMineLocations();
        bool randomLocIsRepeated(int row, int col);
        Move getMove(char mark, char c, int r);


        void reportGameResults(Board gameBoard, bool);
        void reportMove(Move move);
        void printScore(int score);
    };
}

#endif //MINESWEEPER_IO_H
