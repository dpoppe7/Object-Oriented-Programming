#include "board.h"
#include <iostream>
#include <tuple>

namespace Minesweeper {
    Board::Board(){
        for (int r = 0; r < 9; r++){
            for (int c = 0; c < 9; c++){
                cells[r][c].mine = false;
                cells[r][c].label = 0;
                cells[r][c].status = CellStatus::Covered;
            }
        }
        boardSize = {9, 9};
    }

    void Board::resizeBoard(int rows, int cols){
        boardSize = {rows, cols};
    }

    bool Board::onBoard(int r, int c){
        if ((r >= 0 && r <= boardSize.row) && (c >= 0 && c <= boardSize.col)){
            return true;
        }
        return false;
    }


    void Board::placeMinesOnBoard(std::vector<Location> mines){
        //Board board;
        for (const Location &e : mines) {
            cells[e.row][e.col].mine = true;
            cells[e.row][e.col].label = 9;
            cells[e.row][e.col].status = CellStatus::Covered;
        }
    }

    Board Board::updateBoard(Board board, int rows, int cols){
        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (board.cells[r][c].status == CellStatus::Covered &&
                    (board.cells[r][c].mine && board.cells[r][c].label == 9)){

                    if (r-1 >= 0 && !board.cells[r-1][c].mine) board.cells[r-1][c].label++;    //top
                    if (r+1 >= 0 && !board.cells[r+1][c].mine) board.cells[r+1][c].label++;    //bottom

                    if (c-1 >= 0 && !board.cells[r][c-1].mine) board.cells[r][c-1].label++;    //left
                    if (c+1 >= 0 && !board.cells[r][c+1].mine) board.cells[r][c+1].label++;    //right

                    if ((r-1 >= 0 && c-1 >= 0) && !board.cells[r-1][c-1].mine) board.cells[r-1][c-1].label++;  //top-left corner
                    if ((r-1 >= 0 && c+1 >= 0) && !board.cells[r-1][c+1].mine) board.cells[r-1][c+1].label++;  //top-right corner

                    if ((r+1 >= 0 && c-1 >= 0) && !board.cells[r+1][c-1].mine) board.cells[r+1][c-1].label++;  //bottom-left corner
                    if ((r+1 >= 0 && c+1 >= 0) && !board.cells[r+1][c+1].mine) board.cells[r+1][c+1].label++;  //bottom-right corner
                }
            }
        }
        return board;
    }
}