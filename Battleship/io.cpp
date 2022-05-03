#include "io.h"
#include "board.h"
#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;
using std::find;

void printBoard(Board board) {
    cout << setw(3);
    for (int i = 0; i < board.cells.size(); i++) {
        cout << char(i + 'A');
    }cout << endl;

    for (int r = 0; r < board.cells.size(); r++) {
        cout << r << " ";

        for (int c = 0; c < board.cells.size(); c++) {
            char ch = board.cells[r][c];
            cout << ch;
        }
        cout << endl;
    }
    cout << endl;
}

std::string getInput(){
    char col, row, dir;
    cin >> col >> row >> dir;
    string word = "";
    word += toupper(col);
    word += row;
    word += toupper(dir);
    return word;
}

std::string getShot(){
    char col, row;
    cin >> col >> row;
    string word = "";
    word += col;
    word += row;
    return word;
}

void printHit(std::string shipName, std::string point, bool sunk){
    if (sunk) {
        cout << point << ": Hit " << shipName << endl;
        cout << "You sank my " << shipName << "\n" << endl;
    }
    else{
        cout << point << ": Hit " << shipName << "\n" << endl;
    }
}

void printMiss(std::string point){
    cout << point << ": Miss\n" << endl;
}

void printLost(){
    cout << "You lost" << endl;
}

void printYouWin(int turns){
    cout << "You won in " << turns << " turns" << endl;
}


