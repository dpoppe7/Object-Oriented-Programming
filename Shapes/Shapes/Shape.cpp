#include "Shape.hpp"


namespace shapes {
    int Shape::x() const {
        return xCoord;
    }

    int Shape::y() const {
        return yCoord;
    }

    int Shape::size() const {
        return shapeSize;
    }

    Color Shape::color() const {
        return a_color;
    }

    void Shape::move(int x, int y) {
        xCoord = x;
        yCoord = y;
    }

    void Shape::resize(int size) {
        shapeSize = size;
    }

    std::shared_ptr <Shape> Shape::clone() const {
        return std::make_shared<Shape>(*this);
    }

    bool Shape::contains(int x, int y) const {
        if (this->shapeType == ShapeManager::ShapeType::Square){
            return Square::inSquare(x, y);
        }
    }


    void Shape::draw(easywin::Canvas &canvas) const {

    }
}

/*bool Shape::operator ==(const Shape& other) const {
    return equalTo(other);
}
bool Shape::operator !=(const Shape&) const{

}*/
