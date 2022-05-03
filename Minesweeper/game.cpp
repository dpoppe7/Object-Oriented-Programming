#include "game.h"
#include <vector>
#include <iostream>
#include <iomanip>
using std::setw;

namespace Minesweeper{
    void Game::setUpBoard(std::vector<Location> locations) {
        for (const Location &e : locations) {
            gameBoard.setMine(e);
        }
    }

    void Game::setUpCustomBoard(std::vector<Location> locations, std::vector<int> customValues){

        gameBoard.customBoard(customValues[0],customValues[1],customValues[2]);

        for (const Location &e : locations) {
            gameBoard.setMine(e);
        }
    }

    bool Game::OnBoard(Location loc){
        Board board;
        std::tuple<int, int> intLocation;
        intLocation = board.convertLocation(loc);
        int row = std::get<0>(intLocation);
        int col = std::get<1>(intLocation);
        if (gameBoard.cells[row][col].status == Uncovered){
            return true;
        }
        return false;
    }

    void Game::Uncover(Board board, Location startLoc){
        myQueue.push(startLoc);
        while (!myQueue.empty()){
            startLoc = myQueue.front();
            myQueue.pop();
            bool onBoard = OnBoard(startLoc);
            if (onBoard){
                std::cout << "here" << std::endl;
            }
        }
    }
}
