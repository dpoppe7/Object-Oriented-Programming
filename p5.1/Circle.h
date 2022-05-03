#ifndef P5_CIRCLE_H
#define P5_CIRCLE_H

#include "Shape.hpp"

namespace shapes {
    class Circle : public Shape {
    public:
        Circle(int x, int y, int size, Color color) : Shape(x, y, size, color) {
            this->radius = (double) shapeSize / 2;
            this->xCenter = (double) xCoord + radius;
            this->yCenter = (double) yCoord - radius;
        }

        ~Circle() {}

    private:
        double radius;
        double xCenter;
        double yCenter;

    /*protected:
        virtual bool equalTo(const Shape &other) const {
            return other.doEqualTo(*this); // call doEqualTo(Circle) - first virtual dispatch
        }

        virtual bool doEqualTo(const Circle &other) const {
            return other.xCenter == xCenter && other.radius == radius; // second virtual dispatch
        }
        */
    };

}

#endif //P5_CIRCLE_H

