#include "io.h"
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <string>
#include <tuple>
#include <iostream>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;
using std::find;
using std::vector;

namespace Minesweeper {
    void IO::printUncovered(Board board) {
        cout << setw(5);
        int i;
        for (i = 0; i < gameParams.col; i++) {
            cout << char(i + 'A') << " ";
        }cout << endl;

        cout << "  +";
        while (i > 0){
            cout << "--";
            i--;
        }cout << endl;

        for (int r = 0; r < gameParams.row; r++) {
            cout << r + 1 << " | ";
            for (int c = 0; c < gameParams.col; c++) {
                if (c == gameParams.col - 1) {  //print last element
                    cout << board.cells[r][c].label;
                } else {
                    cout << board.cells[r][c].label << " ";
                }
            }cout << endl;
        }cout << endl;
    }

    char IO::cellChar(Board board, int r, int c) {
        char ch;
        if (board.cells[r][c].status == CellStatus::Covered) {
            ch = '.';
        }
        else if (board.cells[r][c].status == CellStatus::Uncovered){
            int num = board.cells[r][c].label;
            if (num == 0){
                ch = ' ';
            }
            else {
                cout << num;
            }
        }
        else if (board.cells[r][c].status == CellStatus::Flagged){
            ch = '*' ;
        }
        return ch;
    }

    void IO::printBoard(Board board, bool isOver){
        cout << setw(5);
        int i;
        for (i = 0; i < gameParams.col; i++) {
            cout << char(i + 'A') << " ";
        }cout << endl;

        cout << "  +";
        while (i > 0){
            cout << "--";
            i--;
        }cout << endl;

        for (int r = 0; r < gameParams.row; r++) {
            cout << r + 1 << " | ";

            if (!isOver) {
                for (int c = 0; c < gameParams.col; c++) {
                    if (c == gameParams.col - 1) {  //print last element
                        cout << cellChar(board, r, c);
                    } else {
                        cout << cellChar(board, r, c) << " ";
                    }
                }
                cout << endl;
            }
            else{   //Last board
                for (int c = 0; c < gameParams.col; c++) {
                    if (c == gameParams.col - 1) {  //print last element without trailing space

                        //print '#' for mines that were not flagged
                        if (board.cells[r][c].mine && board.cells[r][c].status == CellStatus::Covered)
                            cout << '#';
                        else if (!board.cells[r][c].mine && board.cells[r][c].status == CellStatus::Flagged)
                            cout << 'X';
                        else
                            cout << cellChar(board, r, c);
                    }
                    else {

                        //print '#' for mines that were not flagged
                        if (board.cells[r][c].mine && board.cells[r][c].status == CellStatus::Covered)
                            cout << '#' << " ";
                        else if (!board.cells[r][c].mine && board.cells[r][c].status == CellStatus::Flagged)
                            cout << 'X' << " ";
                        else
                            cout << cellChar(board, r, c) << " ";
                    }
                }cout << endl;
            }

        }cout << endl;
    }

    char IO::readSign(){
        char ch;
        cin >> ch;
        return ch;
    }


    gameParameters IO::getGameParameters(){
        int r, c, m;
        cin >> r >> c >> m;

        //Validate parameters
        if (r < 4) r = 4;
        if (r > 9) r = 9;

        if (c < 4) c = 4;
        if (c > 9) c = 9;

        if (m < 4) m = 4;
        if (m > 20) m = 20;

        gameParams.row = r;
        gameParams.col = c;
        gameParams.mines = m;
        return gameParams;
    }

    std::tuple<char, int> IO::readALoc(){
        char c;
        int r;
        cin >> c >> r;
        c = toupper(c);
        return std::make_tuple(c, r);
    }

    std::tuple<int, int> IO::convertLoc_int(char col, int row){
        //Example: B2 to [1][1], D5 to [4][3]
        col = col - 'A';
        row = row - 1;
        return std::make_tuple(row, col);
    }

    Location IO::getLocation(){
        Location location;

        //read Location D5
        std::tuple<char, int> loc = readALoc();
        char c = std::get<0>(loc);
        int r = std::get<1>(loc);

        //convert D5 to [4][3]
        std::tuple<int, int> int_loc = convertLoc_int(c, r);
        int row = std::get<0>(int_loc);
        int col = std::get<1>(int_loc);

        //return a Location
        location.row = row;
        location.col = col;
        return location;
    }


    void IO::getMineLocations(int numMines) {
        Location location;
        while (numMines) {
            location = getLocation();
            gameParams.mineLocations.push_back(location);
            numMines--;
        }
    }

    bool IO::randomLocIsRepeated(int row, int col){
        for (const Location &e : gameParams.mineLocations){
            if (row == e.row && col == e.col){
                //std::cout<< "similar: " << row << col << " " << e.row << e.col << std::endl;
                return true;
            }
        }
        return false;
    }


    void IO::randomMineLocations(){
        Location location;

        // Get the system time.
        unsigned seed = time(0);
        // Seed the random number generator.
        srand(seed);

        //int randNum = rand()%(max-min + 1) + min;
        //number from 4 to 20
        int rand_numMines = rand()%(20-4 + 1) + 4;

        while (rand_numMines){
            //number from 0 to 8
            int row = rand()%(8-0 + 1) + 0;
            int col = rand()%(8-0 + 1) + 0;

            if (gameParams.mineLocations.size() != 0) {
               bool isRepeated = randomLocIsRepeated(row, col);
               while (isRepeated) {
                   //get a different location
                   row = rand() % (8 - 0 + 1) + 0;
                   col = rand() % (8 - 0 + 1) + 0;
                   isRepeated = randomLocIsRepeated(row, col);
               }
            }
            location = {row, col};
            gameParams.mineLocations.push_back(location);

            rand_numMines--;
        }
    }

    Move IO::getMove(char mark, char c, int r){

        if (mark == '!') {
            move.comm = Command::Mark;
        } else if (mark == '?') {
            move.comm = Command::Uncover;
        } else if (mark == '@') {
            move.comm = Command::Sweep;
        }

        //f to F
        c = toupper(c);

        std::tuple<int, int> int_loc = convertLoc_int(c, r);
        int row = std::get<0>(int_loc);
        int col = std::get<1>(int_loc);
        move.loc.row = row;
        move.loc.col = col;

        //cout << move.loc.row << move.loc.col << endl;
        return move;
    }

    void IO::reportMove(Move move){
        if (move.comm == Command::Uncover) cout << "Uncovering ";
        if (move.comm == Command::Mark) cout << "Marking ";

        char col = move.loc.col + 'A';
        cout << col << move.loc.row+1 << endl;
        cout << endl;
    }


    void IO::reportGameResults(Board gameBoard, bool quit){
        bool userLost = false;

        //when there are still cells covered, the user lost
        for (int r = 0; r < gameBoard.boardSize.row; r++){
            for (int c = 0; c < gameBoard.boardSize.col; c++){
                if (gameBoard.cells[r][c].status == CellStatus::Covered){
                    userLost = true;
                    break;
                }
            }
        }

        if (quit){
            cout << "User quit." << endl;
        }
        else {
            if (userLost) {
                cout << "Boom! You died." << endl;
            } else {
                cout << "Congratulations! You win" << endl;
            }
        }
    }


    void IO::printScore(int score){
        cout << "Your score was " << score << "." << endl;
    }

}