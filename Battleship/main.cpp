#include <string>
#include "game.h"
#include "io.h"
using namespace std;
using std::string;

int main() {
    //g++ -std=c++11 board.cpp game.cpp io.cpp main.cpp && ./a.out

    Game game;
    game.LoadShips();

    //GET SHIPS
    int counter = 0;
    while(counter < SHIP_TYPES){
        string input = getInput();

        Coords coord;
        coord = game.setInput(input);
        game.defineShip(coord, counter);
        game.setShips(counter);

        counter++;
    }

    /*Board targetBoard;
    targetBoard = game.primaryBoard();
    printBoard(targetBoard);  //io*/


    //GET SHOTS
    Board yourBoard;
    printBoard(yourBoard);

    bool is_over = false;
    while (!is_over){
        string input = getShot();

        if (game.surrender(input)){
            printLost();
            break;
        }

        POINT point;
        point = game.setPoint(input);

        bool is_hit = game.checkPoint(point);
        bool shot_exist = game.existShot(point);
        if (is_hit){
            string shipName;
            shipName = game.getShipName(point);

            if (!shot_exist){
                game.hitShip(point);
                game.setHit_myBoard(point);
            }

            bool sunk = game.ship_isSunk();
            printHit(shipName, input, sunk);
        }
        else{
            printMiss(input);
            game.setMiss_myBoard(point);
        }

        game.saveShot(point);
        yourBoard = game.userBoard();
        printBoard(yourBoard);

        if (game.win()){
            int totalTurns = game.getTotalTurns();
            printYouWin(totalTurns);
            is_over = true;
        }
    }
}
