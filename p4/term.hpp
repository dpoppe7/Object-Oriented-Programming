#ifndef POLY_START_TERM_HPP
#define POLY_START_TERM_HPP

#include <istream>
#include <ostream>

namespace poly {
    // A term in a polynomial
    struct Term {
        double coefficient;
        unsigned int exponent;
    };

    // Negative term
    inline Term operator-(const Term &t) {
        return { -t.coefficient, t.exponent };
    }


    // Term I/O
    std::istream &operator>>(std::istream &is, Term &term);
    std::ostream &operator<<(std::ostream &os, Term t);


    // Input specific characters
    std::istream &operator>>(std::istream &is, const char &c);
}

#endif //POLY_START_TERM_HPP