#ifndef P5_SQUARE_H
#define P5_SQUARE_H
#include "Shape.hpp"

namespace shapes {
    class Square : public Shape {
    public:
        Square(int x, int y, int size, Color color) : Shape(x, y, size, color) {}

        ~Square() {}
    };
}
#endif //P5_SQUARE_H
