#include "io.h"
#include <iostream>
#include <iomanip>
#include <string>

using std::endl;
using std::setw;
using std::cout;
using std::cin;


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
}

/*struct Point getPoints(struct Point& point){
    char c;
    int r;
    char dir;

    cin >> c >> r >> dir;

    c = toupper(c); //Uppercase
    dir = toupper(dir);

    point.col = c;
    point.row = r;
    if (dir == 'H') point.direction = true;
    if (dir == 'V') point.direction = false;

    return point;
}*/

//Optional to check all ships
/*void printShipPoints(std::vector<std::pair<char, int>> ships){
    for (const auto& p : ships){
        std::cout << p.first << ", " << p.second << " " << p. << std::endl;
    }
}*/
/*struct Shot getShot(struct Shot& shot){
    char c;
    int r;
    cin >> c >> r;
    shot.col = c;
    shot.row = r;
    return shot;
}*/

/*void printBoard(Board board){
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
}*/
/*void printIsOver(){
    cout << "You lost" << endl;
}*/

/*void printHit(Shot shot, string name){
    cout << shot.col << shot.row << ": Hit " << name << endl;
}
void printMiss();*/