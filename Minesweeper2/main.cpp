#include "io.h"
#include "game.h"
#include <vector>
#include <iostream>
#include <tuple>


using Minesweeper::IO;
using Minesweeper::Game;
using Minesweeper::Location;
using Minesweeper::gameParameters;

gameParameters readGameParams(IO io){
    char ch = io.readSign();
    if (ch == '#'){
        io.gameParams = io.getGameParameters();
    }
    else if (ch == '!'){   //'!' Default board size
        io.gameParams = {6,6,4};
    }

    //Getting mines
    if(ch == '?'){         // Max board size
        io.randomMineLocations();
        io.gameParams.row = 9;
        io.gameParams.col = 9;
    }

    io.getMineLocations(io.gameParams.mines);

    return io.gameParams;
}

Minesweeper::Board setUpGame(Game game, int rows, int cols, std::vector<Location> minesVec){
    /*for (const Location &e : minesVec) {
        std::cout << e.row << e.col << " ";
    }std::cout << std::endl;*/

    game.gameBoard.resizeBoard(rows, cols);

    //Place mines
    game.gameBoard.placeMinesOnBoard(minesVec);

    game.setUpGameBoard(rows, cols);

    return game.gameBoard;
}

std::tuple<bool, bool, Minesweeper::Board> playGame(IO io , Game game){
    bool isOver = false;
    bool userQuit = false;
    char sign, c;
    int r;
    while ((std::cin >> sign >> c >> r && !isOver)){
        io.printUncovered(game.gameBoard);


        //get move
        io.move = io.getMove(sign, c, r);

        //make move
        if (io.move.comm == Minesweeper::Command::Uncover)
            game.uncoverLoc(io.move.loc);

        if (io.move.comm == Minesweeper::Command::Mark)
            game.markLoc(io.move.loc);

        if (io.move.comm == Minesweeper::Command::Sweep)
            game.sweepInLoc(io.move.loc);

        io.reportMove(io.move);    //Ex. Uncovering F1
        isOver = game.gameOver();  //true when mine is uncovered

        if (!isOver) {
            io.printBoard(game.gameBoard, false);
        }

    }

    if (sign == 'Q' || sign == 'q') {
        isOver = true;
        userQuit = true;
    }

    return std::make_tuple(isOver, userQuit, game.gameBoard);
}

int main(){
    IO io;
    Game game;

    //read Game Parameters
    io.gameParams = readGameParams(io);

    //Set up Game
    game.gameBoard = setUpGame(game, io.gameParams.row, io.gameParams.col, io.gameParams.mineLocations);

    //Print board
    io.printBoard(game.gameBoard, false);

    //playGame
    std::tuple<bool, bool, Minesweeper::Board> gameOver = playGame(io, game);
    bool gameOver_isOver = std::get<0>(gameOver);   //true if Game Over
    bool gameOver_quit = std::get<1>(gameOver);     //true if user Quit
    game.gameBoard = std::get<2>(gameOver);         //current game board

    //Report Results if game is over
    if (gameOver_isOver){
        io.printUncovered(game.gameBoard);

        io.printBoard(game.gameBoard, true);
        io.reportGameResults(game.gameBoard, gameOver_quit);

        //Print Score
        int score = game.getScore(game.gameBoard);
        io.printScore(score);
    }

    return 0;
}