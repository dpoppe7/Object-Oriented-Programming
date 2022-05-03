#ifndef P5_CIRCLE_H
#define P5_CIRCLE_H
#include "Shape.hpp"

class Circle : public Shape {
    int radius;
    Point center;

public:
    Circle(int x, int y, int size, Color color) : Shape(x, y, size, color){
        this->radius = (double)shapeSize / 2;
        this->center.x = (double)xCoord + radius;
        this->center.y = (double)yCoord - radius;
    }

};

#endif //P5_CIRCLE_H
