#ifndef MINESWEEPER_GAME_H
#define MINESWEEPER_GAME_H
#include <vector>
#include "board.h"
#include <deque>
#include <queue>

namespace Minesweeper {
    class Game {
        bool userWon = false;
        int numOfMines = 0;
    public:
        Board gameBoard;
        int score = 0;
        bool mineUncovered = false;
        int totalCells;


        void setUpGameBoard(int row, int col);
        int getNumMines();

        void uncoverLoc(Location loc);
        void markLoc(Location loc);
        void sweepInLoc(Location loc);

        std::vector<Location> getCellsAroundLocation(int row, int col);
        void Recursive(Board &gameBoard, Location loc);


        bool isMineUncovered(Location loc);

        bool gameOver();
        bool ifUserWon();

        int getScore(Board gameBoard);
        void setTotalCells(Board gameBoard);
        int getTotalCells();
    };
}

#endif //MINESWEEPER_GAME_H
