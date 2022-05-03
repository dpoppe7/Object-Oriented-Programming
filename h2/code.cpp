#include <iostream>

using namespace std;

class Rectangle {
    int left, top, right, bottom;
    int width, height;

public:
    Rectangle() :
            left{}, top{}, right{}, bottom{}, width{}, height{}{ }
    Rectangle(int left, int top, int right, int bottom) :
            left{ left }, top{ top }, right{ right }, bottom{ bottom } { }

    int getLeft() {return left;}
    void setLeft(int value) {left = value;}

    int getRight() {return right;}
    void setRight(int value) {right = value;}

    int getTop() {return top;}
    void setTop(int value) {top = value;}

    int getBottom() {return bottom;}
    void setBottom(int value) {bottom = value;}

    int getWidth() {return width;}
    void setWidth(int value) {width = value;}

    int getHeight() {return height;}
    void setHeight(int value) {height = value;}
};

int main(){
    Rectangle rect;
    rect.getLeft();
    rect.getTop();
    rect.getRight();
    rect.getBottom();
    rect.getWidth();
    rect.getHeight();
    return 0;
}