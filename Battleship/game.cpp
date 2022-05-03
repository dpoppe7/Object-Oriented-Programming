#ifndef GAME_CPP
#define GAME_CPP
#include <vector>
#include <string>
#include "game.h"
#include "board.h"

using std::vector;
using std::string;

Board Game::primaryBoard(){
    return primary;
}

Board Game::userBoard(){
    return board;
}

Coords Game::setInput(string input) {
    Coords coords;
    int c = input[0] - 'A';
    int r = input[1] - '0';
    int d;
    if (input[2] == 'H') d = 0;
    if (input[2] == 'V') d = 1;
    //cout << c << r << d << endl;
    coords.c = c;
    coords.r = r;
    coords.dir = d;
    return coords;
}

void Game::defineShip(Coords coord, int thisShip) {
    myShip.shipType.point->X = coord.c;
    myShip.shipType.point->Y = coord.r;
    myShip.direction = (DIRECTION)coord.dir;

    myShip.shipType.length = ship[thisShip].length;
    myShip.shipType.name = ship[thisShip].name;
    //coord are 0: FIX
    //return myShip;
}

void Game::setShips(int thisShip){
    int c, r;
    char ch = '0' + thisShip;

    for (int i = 0; i < myShip.shipType.length; ++i){
        if (myShip.direction == HORIZONTAL) {
            myShip.shipType.point[i].X = myShip.shipType.point->X + i;
            myShip.shipType.point[i].Y = myShip.shipType.point->Y;
            c = myShip.shipType.point[i].X;
            r = myShip.shipType.point[i].Y;
            //cout << x << " " << y << endl;
            primary.setPoint_Board(r, c, ch);
        }
        if (myShip.direction == VERTICAL) {
            myShip.shipType.point[i].Y= myShip.shipType.point->Y + i;
            myShip.shipType.point[i].X = myShip.shipType.point->X;
            c = myShip.shipType.point[i].X;
            r = myShip.shipType.point[i].Y;
            //cout << x << " " << y << endl;
            primary.setPoint_Board(r, c, ch);
        }
    }
}


POINT Game::setPoint(std::string input){
    POINT point;
    int c = toupper(input[0]) - 'A';
    int r = input[1] - '0';

    point.X = r;
    point.Y = c;
    return point;
}

bool Game::checkPoint(POINT point){
    int r = point.X;
    int c = point.Y;
    //char ch = primary.cells[r][c];
    if (primary.cells[r][c] != Cell::Empty){
        return true;
    }
    return false;
}

string Game::getShipName(POINT point){
    int r = point.X;
    int c = point.Y;
    int at;
    if (primary.cells[r][c] == Cell::Carrier) at = 0;
    if (primary.cells[r][c] == Cell::Battleship) at = 1;
    if (primary.cells[r][c] == Cell::Cruiser) at = 2;
    if (primary.cells[r][c] == Cell::Submarine) at = 3;
    if (primary.cells[r][c] == Cell::Destroyer) at = 4;
    return ship[at].name;
}

bool Game::existShot(POINT point){
    for (auto& e: Shots) {
        if (e.first == point.X && e.second == point.Y){
            return true;
        }
    }
    return false;
}

void Game::saveShot(POINT point){
    int x = point.X;
    int y = point.Y;
    Shots.insert({x, y});
    /*for (auto& e: Shots) {
        cout << e.first << " " << e.second << endl;
    }*/
}

void Game::hitShip(POINT point){
    int r = point.X;
    int c = point.Y;
    int at;
    if (primary.cells[r][c] == Cell::Carrier) at = 0;
    if (primary.cells[r][c] == Cell::Battleship) at = 1;
    if (primary.cells[r][c] == Cell::Cruiser) at = 2;
    if (primary.cells[r][c] == Cell::Submarine) at = 3;
    if (primary.cells[r][c] == Cell::Destroyer) at = 4;
    ship[at].length -= 1;
    aShip_length =  ship[at].length;
}

bool Game::ship_isSunk(){
    if (aShip_length == 0) {
        remainingShips--;
        return true;
    }
    return false;
}

void Game::setHit_myBoard(POINT point){
    board.setShot_Board(point.X, point.Y, Cell::X);
}

void Game::setMiss_myBoard(POINT point){
    board.setShot_Board(point.X, point.Y, Cell::O);
}

bool Game::surrender(std::string input) {
    if ((input[0] == 'Q'|| input[0] == 'q') && input[1] == '0')
        return true;
    return false;
}

bool Game::win(){
    if (remainingShips == 0)
        return true;
    return false;
}

int Game::getTotalTurns(){
    return Shots.size();
}


/*void Game::setShip(Point point, int count){
    std::vector<Ships> ships_points;
    if (point.direction){
        for (int i = 0; i < shipTypes[count].length; i++){
            ships_points.push_back(std::make_pair(point.col + i, point.row));
        }
    }else{
        for (int i = 0; i < shipTypes[count].length; i++){
            ships_points.push_back(std::make_pair(point.col, point.row + i));
        }
    }

}*/

/*void Game::setShipPoints(Point point){
    //std::vector<Ships> ships_points;
}

bool Game::gameOver(Shot shot){
    if ((shot.col == 'Q' || shot.col == 'q') &&
        (shot.row == 0)){
        return true;
    }
    return false;
}

bool Game::isHit(Shot shot){
    for (const auto& pair : ships){
        if ((pair.first == shot.col) && (pair.second == shot.row)){
            return true;
        }
    }
    return false;
}*/

/*std::string Game::getShipType(Shot shot){
    int index = 0;
    for(int i = 0; i < ship.size(); i++) {
        for (int j = 0; j < NUM_SHIPS <
        }
    }
    return shipTypes[index].name;
}*/
#endif