#include "ShapeManager.hpp"
#include "Shape.hpp"
#include "Circle.h"
#include "Triangle.h"
#include "Square.h"
#include <iostream>

int main(){
    /*shapes::Triangle c(100, 200, 300, 0xff00);
    shapes::Shape* p = &c;
    std::cout << p->x() << " " << p->y() << " " << p->size() << " " << p->color() << std::endl;
    p->move(40, 50);
    p->resize(60);
*/

    using shapes::Shape;
    using shapes::ShapeManager;
    using std::shared_ptr;
    shared_ptr<Shape> p = ShapeManager::makeShape(
            ShapeManager::ShapeType::Circle,
            987,
            654,
            321,
            0xfacade
    );

    std::cout << p->x() << std::endl;
    std::cout << p->y() << std::endl;
    std::cout << p->size() << std::endl;
    std::cout << p->color() << std::endl;

    /*p = ShapeManager::makeShape(
            ShapeManager::ShapeType::Square,
            987,
            654,
            321,
            0xfacade
    );
    ASSERT_EQ(typeid(*p), typeid(shapes::Square));
    ASSERT_EQ(p->x(), 987);
    ASSERT_EQ(p->y(), 654);
    ASSERT_EQ(p->size(), 321);
    ASSERT_EQ(p->color(), 0xfacade);
    p = ShapeManager::makeShape(
            ShapeManager::ShapeType::Triangle,
            987,
            654,
            321,
            0xfacade
    );
    ASSERT_EQ(typeid(*p), typeid(shapes::Triangle));
    ASSERT_EQ(p->x(), 987);
    ASSERT_EQ(p->y(), 654);
    ASSERT_EQ(p->size(), 321);
    ASSERT_EQ(p->color(), 0xfacade);
*/
    return 0;
}

