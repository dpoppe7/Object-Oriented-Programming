Damaris Poppe

Shortcomings: It took me a lot of time to understand the implementation of linked list. My program is failing with the move assignment and move constructor operators, also with the clear function. I'm not quite sure why there is a conflict when the destructor and the clear method that uses a deleteNodes function.
Unfortunately I couldn't get the Google test setup. 
I think I spent too many days trying to set it up, trying to understand the program and the code given.

Strengths: Since I couldn't configure the tests I spent more time making a main file and it helped me understand what we were doing with the objects and specially the operators. 




Command lines used:

//For creating the objects and adding terms with addTerm method
poly::Polynomial p, q;
p.addTerm({ 4, 8 });
p.addTerm({ -3, 2 });

 	g++ -std=c++11 main.cpp &&  ./a.out 



//When input is read from a in.txt file:
poly::Polynomial p;
    std::cin >> p ;
    std::cout << p;
    std::cout << std::endl;


//in file
p(2 x^2 + 8 x - 6)

	g++ -std=c++11 main.cpp &&  ./a.out < in


*Note:
I realized that std::can was not reading a polynomial if it was written like this:
	p(2x^2 + 8x - 6)

Instead it had to contain spaces after each coefficient.
	p(2 x^2 + 8 x - 6)

The reason was that the istream extraction operator internally uses num_get::do_get, which performs tasks for a double (Selects a conversion specifier, for double that's %lg)
An input like a hexadecimal number "0x" would contain 'x' and neither a trailing "a", "b", "x" are an accepted sufficient for the %lg conversion specifier.





My main.cpp File:

//main.cpp
#include "polynomial.hpp"
#include "term.hpp"
#include "polynomial.cpp"
#include "term.cpp"
#include <sstream>
#include <string>
#include <iostream>

int main(){

    ///Print Polynomial
    /*
    poly::Polynomial p;
    std::cin >> p ;
    std::cout << p;
    std::cout << std::endl;

    std::cout << std::endl;
    */


    ///Add a term
    /*
    poly::Term term;
    std::cin >> term ;
    std::cout << term;
    std::cout << std::endl;

    std::cout << "Add term: ";
    p.addTerm(term);
    std::cout << p;
    std::cout << std::endl;

    std::cout << std::endl;
    */


    ///Get degree of poly
    /*
    std::cout << "degree: " << p.degree() << std::endl;

    std::cout << std::endl;
    */


    ///Get coefficient for exponent
    /*
    unsigned int expo;
    std::cin >> expo;
    std::cout << "coeff for " << expo << ": " << p.coefficientFor(expo);
    std::cout << std::endl;

    std::cout << std::endl;
    */


    ///clear polynomial
    /*
    poly::Polynomial p;
    poly::Polynomial q;
    std::cin >> p;
    std::cin >> q;
    std::cout << "clear poly : " << p << std::endl;
    p.clear();

    std::cout << std::endl;
    */



    ///OPERATORS
    /*
    poly::Polynomial p;
    poly::Polynomial q;
    std::cin >> p;
    std::cin >> q;
    std::cout << p << std::endl;
    std::cout << q << std::endl;

    std::cout << "If P1 == P2 : " << std::endl;
    if (p == q)
        std::cout << "true (==)" << std::endl;
    else
        std::cout << "false (==)" << std::endl;


    std::cout << std::endl;
    std::cout << "If P1 != P2 : " << std::endl;
    if (p != q)
        std::cout << "true (!=)" << std::endl;
    else
        std::cout << "false (!=)" << std::endl;


    std::cout << std::endl;
    std::cout << "If P1 < P2 : " << std::endl;
    if (p < q)
        std::cout << "true (<)" << std::endl;
    else
        std::cout << "false (<)" << std::endl;


    std::cout << std::endl;
    std::cout << "If P1 > P2 : " << std::endl;
    if (p > q)
        std::cout << "true (>)" << std::endl;
    else
        std::cout << "false (>)" << std::endl;*/


    ///Copy assignment
    /*
    poly::Polynomial p, q;
    p.addTerm({ 4, 8 });
    p.addTerm({ -3, 2 });
    std::cout << p << std::endl;
    std::cout << q << std::endl;

    q = p;

    std::cout << p << std::endl;
    std::cout << q << std::endl;
    */


    ///Copy constructor
    /*poly::Polynomial p;
    p.addTerm({ 4, 8 });
    p.addTerm({ -3, 2 });
    poly::Polynomial q = p;
    p.addTerm({ 5, 6 });
    p.addTerm({ 3, 2 });
    std::cout << p << std::endl;
    std::cout << q << std::endl;*/


    ///Move assignment
    /*poly::Polynomial p, q;
    p.addTerm({ 4, 8 });
    p.addTerm({ -3, 2 });
    q = std::move(p);
    std::cout << q << std::endl;*/

    ///Default Constructor
    /* poly::Polynomial p;
    p.addTerm({ 0, 8 });
    p.addTerm({ 0, 5 });
    std::cout << p << std::endl;*/

    ///Move Constructor
    /*poly::Polynomial p, q;
    p.addTerm({ 4, 8 });
    p.addTerm({ -3, 2 });
    q = std::move(p);
    p.addTerm({ 5, 6 });
    p.addTerm({ 3, 2 });
    std::cout << p << std::endl;
    std::cout << q << std::endl;*/


    /// Move
    /*
    poly::Polynomial p;
    poly::Polynomial q = std::move(p);
    std::cout << p << std::endl;
    */
    
    return 0;
}