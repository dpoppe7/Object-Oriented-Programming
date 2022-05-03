
#ifndef TEMPLATE_LABELED_HPP
#define TEMPLATE_LABELED_HPP
#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Labeled{
    string label;
    T value;
};

template <typename T>
ostream& operator<<(ostream& out, Labeled<T> const& t){
    out << t.label << ": " << t.value <<endl;
}
#endif //TEMPLATE_LABELED_HPP