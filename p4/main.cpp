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
    /*poly::Polynomial p;
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