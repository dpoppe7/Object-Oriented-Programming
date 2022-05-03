#include "io.h"
#include <iomanip>
#include <cctype>
#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;
using std::find;
using std::vector;

namespace Minesweeper {

    Location IO::readColRow() {
        Location loc;
        char r;
        int c;

        cin >> r >> c;
        c = toupper(c);

        loc = (Location) {.row = r, .col = c};
        return loc;
    }

    char IO::readSign(){
        char sign;
        cin >> sign;
        return sign;
    }

    vector <Location> IO::getMines(){
        vector <Location> mines;
        char sign = readSign();
        if (sign == '!'){
            mines = getMineLocations();
        }
        else if (sign == '#'){
            getCustomGrid();
            mines = getMineLocations();
        }
        return mines;
    }

    vector <int> IO::getCustomGrid(){
        char chX, chY, chM;
        cin >> chX >> chY >> chM;

        int x = chX - '0';
        int y = chY - '0';
        int m = chM - '0';

        //input validation
        if (x < 4) x = 4;
        if (x > 9) x = 9;

        if (y < 4) y = 4;
        if (y > 9) y = 9;

        /*if (m < 4) y = 4;
        if (m > 20) y = 20;*/

        customValues.insert(customValues.end(), {x, y, m});
        return customValues;
    }

    vector <Location> IO::getMineLocations() {
        vector <Location> mines;
        Location loc;
        char ch;
        cin >> ch;
        while (cin >> loc.row && cin >> loc.col){
            mines.push_back(loc);
        }
        //cin >>  ch;
        //cout <<  ch << endl;
        /*Board board;
        board.gridSize.totalMines = mines.size();

        cout << "PRINT MINE LOCATIONS" << endl;
        for (const Location &e : mines) {
            cout << e.row << e.col << ' ';
        }cout << endl;*/
        return mines;
    }

    void IO::getMove(){
        Move move;
        cout << "Flag 1" << endl;
        char ch = readSign();
        cout << "Flag 2" << endl;
        cout << ch << endl;
        cout << "Flag 3" << endl;

        //if (com == '?') move.com = Uncover;
        //if (com == '!') move.com = Mark;
        //move.loc.row = r;
        //move.loc.col = c;
        //return move;
    }

    void IO::reportMove(Move move){
        cout << "Uncovering " << move.loc.row << move.loc.col << endl;
    }

    char IO::showCellLabel(Board board, int r, int c) {
        char ch;
        if (board.cells[r][c].status == Covered) {
            ch = board.cells[r][c].label;
        }
        else if (board.cells[r][c].status == Uncovered){
            ch = '.';
        }
        else if (board.cells[r][c].status == Flagged){
            ch = '*' ;
        }
        return ch;
    }


    void IO::printBoard(Board board) {
        cout << setw(5);
        int i;
        for (i = 0; i < board.cells[0].size(); i++) {
            cout << char(i + 'A') << " ";
        }cout << endl;

        cout << "  +";
        while (i > 0){
            cout << "--";
            i--;
        }cout << endl;

        for (int r = 0; r < board.cells.size(); r++) {
            cout << r + 1 << " | ";
            for (int c = 0; c < board.cells[0].size(); c++) {
                if (c == board.cells[0].size() - 1) {  //print last element
                    cout << showCellLabel(board, r, c);
                } else {
                    cout << showCellLabel(board, r, c) << " ";
                }
            }cout << endl;
        }cout << endl;
    }

    void IO::printUncovered(Board board) {
            cout << setw(5);
            int i;
            for (i = 0; i < board.cells[0].size(); i++) {
                cout << char(i + 'A') << " ";
            }cout << endl;

            cout << "  +";
            while (i > 0){
                cout << "--";
                i--;
            }cout << endl;

            for (int r = 0; r < board.cells.size(); r++) {
                cout << r + 1 << " | ";
                for (int c = 0; c < board.cells[0].size(); c++) {
                    if (c == board.cells[0].size() - 1) {  //print last element
                        cout << board.cells[r][c].label;
                    } else {
                        cout << board.cells[r][c].label << " ";
                    }
                }cout << endl;
            }cout << endl;
    }


}