#ifndef P5_TRIANGLE_H
#define P5_TRIANGLE_H
#include "Shape.hpp"

namespace shapes {
    class Triangle : public Shape {
    public:
        Triangle(int x, int y, int size, Color color) : Shape(x, y, size, color) {}

        virtual ~Triangle() {}
    };
}
#endif //P5_TRIANGLE_H
