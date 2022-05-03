#include "Square.hpp"

bool Square::inSquare(int x, int y){
    if (x >= left && x <= right){
        if (y >= top && y <= bottom){
            return true;
        }
    }
    return false;
}
