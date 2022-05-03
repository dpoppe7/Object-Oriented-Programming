#include "io.h"
#include "game.h"
#include <vector>
#include <iostream>

/*void getTheMines(Minesweeper::IO io){
    std::vector<Minesweeper::Location> mineLocations = io.getMines();
}*/

int main(){
    Minesweeper::Board myBoard;
    Minesweeper::IO io;
    Minesweeper::Game game;

    io.printBoard(myBoard);


    //Get the Mine Locations (with IO)
    std::vector<Minesweeper::Location> mineLocations = io.getMines();

    //Set up the board (with Game)
    /*if (!io.customValues.empty()){
        game.setUpCustomBoard(mineLocations, io.customValues);
    }
    else{
        game.setUpBoard(mineLocations);
    }

    ///Print board
    std::cout << "Uncovered Board" << std::endl;
    io.printUncovered(game.gameBoard);
    io.printBoard(game.gameBoard);*/

    // Get a move from the player (with IO)
    io.getMove();
    //io.move = io.getMove();
    //io.reportMove(io.move);
    return 0;
}