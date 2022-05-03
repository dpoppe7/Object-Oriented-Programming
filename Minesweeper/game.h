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
        int score;

        std::queue<Location> myQueue;

        void setUpBoard(std::vector<Location> locations);
        void setUpCustomBoard(std::vector<Location> locations, std::vector<int> customValues);

        bool OnBoard(Location loc);

        void Uncover(Board board, Location startLoc);
    };
}

#endif //MINESWEEPER_GAME_H
