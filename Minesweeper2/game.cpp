#include "game.h"
#include <vector>
#include <iostream>
#include <iomanip>

namespace Minesweeper{
    void Game::setUpGameBoard(int row, int col){
        gameBoard = gameBoard.updateBoard(gameBoard, row, col);
    }

    bool Game::gameOver(){
        if (mineUncovered){
            return true;
        }
        else{
            int markedCells = 0;
            for (int r = 0 ; r < gameBoard.boardSize.row; r++){
                for (int c = 0 ; c < gameBoard.boardSize.col; c++){
                    if (gameBoard.cells[r][c].status == CellStatus::Uncovered ||
                       (gameBoard.cells[r][c].status == CellStatus::Flagged && gameBoard.cells[r][c].mine)){
                        markedCells++;
                    }
                }
            }
            std::cout << markedCells << std::endl;
            //no more moves
            int totalCells = gameBoard.boardSize.row * gameBoard.boardSize.col;
            std::cout << totalCells << std::endl;
            if (markedCells == totalCells){
                return true;
            }
        }
        return false;
    }

    std::vector<Location> Game::getCellsAroundLocation(int r, int c){
        std::vector<Location> cellsAround;
        Location loc;
        if ((r-1 >= 0) && (!gameBoard.cells[r-1][c].mine && gameBoard.cells[r-1][c].status != CellStatus::Flagged)) {
            loc = {r-1, c};  //top
            cellsAround.push_back(loc);
        }
        if ((r+1 >= 0) && (!gameBoard.cells[r+1][c].mine && gameBoard.cells[r+1][c].status != CellStatus::Flagged)) {
            loc = {r + 1, c};    //bottom
            cellsAround.push_back(loc);
        }

        if ((c-1 >= 0) && (!gameBoard.cells[r][c-1].mine && gameBoard.cells[r][c-1].status != CellStatus::Flagged)) {
            loc = {r, c-1} ;    //left
            cellsAround.push_back(loc);
        }
        if ((c+1 >= 0) && (!gameBoard.cells[r][c+1].mine && gameBoard.cells[r][c+1].status != CellStatus::Flagged)) {
            loc = {r, c+1} ;    //right
            cellsAround.push_back(loc);
        }

        if ((r-1 >= 0 && c-1 >= 0) && (!gameBoard.cells[r-1][c-1].mine && gameBoard.cells[r-1][c-1].status != CellStatus::Flagged)) {
            loc = {r-1, c-1};   //top-left corner
            cellsAround.push_back(loc);
        }
        if ((r-1 >= 0 && c+1 >= 0) && (!gameBoard.cells[r-1][c+1].mine && gameBoard.cells[r-1][c+1].status != CellStatus::Flagged)) {
            loc = {r - 1, c+1};  //top-right corner
            cellsAround.push_back(loc);
        }

        if ((r+1 >= 0 && c-1 >= 0) && (!gameBoard.cells[r+1][c-1].mine && gameBoard.cells[r+1][c-1].status != CellStatus::Flagged)) {
            loc = {r + 1, c-1};  //bottom-left corner
            cellsAround.push_back(loc);
        }
        if ((r+1 >= 0 && c+1 >= 0) && (!gameBoard.cells[r+1][c+1].mine && gameBoard.cells[r+1][c+1].status != CellStatus::Flagged)) {
            loc = {r + 1, c+1}; //bottom-right corner
            cellsAround.push_back(loc);
        }

        return cellsAround;
    }

    void Game::uncoverLoc(Location loc){
        if (isMineUncovered(loc)){
            mineUncovered = true;
        }else {
            if (gameBoard.cells[loc.row][loc.col].label == 0){
                Recursive(gameBoard, loc);
            }
            gameBoard.cells[loc.row][loc.col].status = CellStatus::Uncovered;
        }
    }

    void Game::Recursive(Minesweeper::Board& gameBoard, Location loc){
        if (gameBoard.onBoard(loc.row, loc.col)){
            if(gameBoard.cells[loc.row][loc.col].status != CellStatus::Uncovered){
                gameBoard.cells[loc.row][loc.col].status = CellStatus::Uncovered;

                if(gameBoard.cells[loc.row][loc.col].label == 0){
                    for (int r = loc.row - 1; r <= loc.row + 1; r++) {
                        for (int c = loc.col - 1; c <= loc.col + 1; c++) {

                            //std::cout << r << c << std::endl;
                            Recursive(gameBoard, {r, c});
                        }
                    }
                }
            }
        }
    }

    void Game::markLoc(Location loc){
        //if cell is already flagged, remove flag
        if (gameBoard.cells[loc.row][loc.col].status == CellStatus::Flagged){
            gameBoard.cells[loc.row][loc.col].status = CellStatus::Covered;
        }else {
            gameBoard.cells[loc.row][loc.col].status = CellStatus::Flagged;
        }
    }

    void Game::sweepInLoc(Location loc){
        if (isMineUncovered(loc)){
            mineUncovered = true;
        }else {
            //uncover cell
            gameBoard.cells[loc.row][loc.col].status = CellStatus::Uncovered;

            //uncover cells around it
            std::vector <Location> cellsAround = getCellsAroundLocation(loc.row, loc.col);
            for (const Location &e : cellsAround) {
                gameBoard.cells[e.row][e.col].status = CellStatus::Uncovered;

                if (gameBoard.cells[e.row][e.col].label == 0) {
                    /*//uncover cell with 0
                    gameBoard.cells[e.row][e.col].status = CellStatus::Uncovered;

                    //uncover cells around the 0
                    std::vector <Location> cellsAroundZero = getCellsAroundLocation(e.row, e.col);
                    for (const Location &i : cellsAroundZero) {
                        gameBoard.cells[i.row][i.col].status = CellStatus::Uncovered;
                    }*/
                    Recursive(gameBoard, loc);
                }
            }
        }
    }

    bool Game::isMineUncovered(Location loc){
        if (gameBoard.cells[loc.row][loc.col].mine){
            return true;
        }
        return false;
    }

    int Game::getScore(Board gameBoard){
        std::cout << "Location is: " << std::endl;
        for (int r = 0 ; r < gameBoard.boardSize.row; r++){
            for (int c = 0 ; c < gameBoard.boardSize.col; c++) {
                if ((gameBoard.cells[r][c].status == CellStatus::Uncovered && !gameBoard.cells[r][c].mine)) {
                    //std::cout << r << c << " ";
                    score++;
                }
            }//std::cout << std::endl;
        }
        return score;
    }


}
