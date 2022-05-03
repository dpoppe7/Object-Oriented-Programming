#include <utility>
#include <iostream>

int foo (int i ) {
    if ( i < 100)
        throw (int )100;
    if ( i > 500)
        throw ( double )3.14;
    return i / 10;
}

int main () {
    int x , y = 0;
    std::cin >> x ;
    try {
        if ( x < 0)
            throw x ;
        try {
            y = foo ( x );
        }
        catch (int i ) {
            y = i ;
        }
    }
    catch ( double d ) {
        y = -1;
    }
    catch (...) {
        y = -2;
    }
    std::cout << std::endl << y << std::endl ;
    return 0;
}

