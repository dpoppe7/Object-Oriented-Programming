#include "board.h"
#include <iostream>
#include <tuple>

namespace Minesweeper {
    Board::Board(){
        //cells.resize(6, std::vector<Cell>(6));
        cells.resize(6);
        for (int r = 0; r < 6; r++) {
            for (int c = 0; c < 6; c++) {
                cells[r][c].label = '.';
            }
        }
        gridSize = {6,6, 0};
    }

    void Board::customBoard(int rows, int cols, int mines){
        //cells[0].resize(cols);
        //cells.resize(rows);
        //std::cout << "Size: " << cells.size() << " | " << cells[0].size() << std::endl;

        cells.resize(rows);
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                cells[r][c].label = '.';
            }
        } //problem: rows will not be assigned a label after r = 6


        /*for (int i = 0; i < cells.size(); i++) {
            for (int j = 0; j < cells[i].size(); j++)
                std::cout << cells[i][j].label << " ";
            std::cout << std::endl;
        }*/

        //std::cout << "Number of dots: " << t << std::endl;
        //std::cout << "Size: " << cells.size() << " | " << cells[0].size() << std::endl;
        gridSize = {rows, cols, mines};
    }

    Cell Board::setCellAtLoc(Location loc){
        Cell cell = cells[loc.row][loc.col];
        return cell;
    }

    std::tuple<int, int> Board::convertLocation(Location loc){
        //Example: B2 to [1][1], D5 to [4][3]
        int row, col;
        row = loc.col - 1;
        col = loc.row - 'A';
        //std::cout << row << col << " " << std::endl;
        return std::make_tuple(row, col);
    }

    void Board::setMine(Location loc){
        std::tuple<int, int> intLocation = convertLocation(loc);
        int row = std::get<0>(intLocation);
        int col = std::get<1>(intLocation);

        cells[row][col].label = '#';
        cells[row][col].status = Uncovered;
    }

    void Board::setCellStatus(Location loc){

    }
}