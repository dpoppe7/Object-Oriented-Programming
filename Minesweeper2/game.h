#ifndef MINESWEEPER_GAME_H
#define MINESWEEPER_GAME_H
#include <vector>
#include "board.h"
#include <deque>
#include <queue>

namespace Minesweeper {
    class Game {
    public:
        Board gameBoard;
        int score = 0;
        bool mineUncovered = false;

        void setUpGameBoard(int row, int col);

        void uncoverLoc(Location loc);
        void markLoc(Location loc);
        void sweepInLoc(Location loc);

        std::vector<Location> getCellsAroundLocation(int row, int col);
        void Recursive(Board &gameBoard, Location loc);


        bool isMineUncovered(Location loc);

        bool gameOver();

        int getScore(Board gameBoard);
    };
}

#endif //MINESWEEPER_GAME_H
