#ifndef P5_SQUARE_H
#define P5_SQUARE_H
#include "Shape.hpp"

class Square : public Shape{
    int left,
    int top,
    int right,
    int bottom,
public:
    Square(int x, int y, int size, Color color) : Shape(x, y, size, color) {
        this->color = color;
        left = x;
        right = x;
        top = y;
        bottom = y;
    }

    bool inSquare(int x, int y);
};

#endif //P5_SQUARE_H
