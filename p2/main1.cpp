#include <string>
#include <iostream>
#include <iomanip>
#include "game.h"
#include "io.h"
using namespace std;
using std::string;

int main() {
    Game game;


    /* int count = 0;
   while(count < 5){
       Point point;
       point = getPoints(point);
       game.setShipPoints(point);
       //game.setShip(point, count);
       count++;
   }
   //printShipPoints(game.ships);
   printBoard(game.primary);

   bool is_over = false;
   while (!is_over){
       Shot shot;
       shot = getShot(shot);

       if (game.gameOver(shot)){
           printIsOver();
           is_over = true;
       }

       bool is_hit = game.isHit(shot);
       if (is_hit){
           string shipName = game.getShipType(shot);
           printHit(shot, shipName);
       }
   }*/
}