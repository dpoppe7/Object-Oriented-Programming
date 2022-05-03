#include "gtest/gtest.h"
#include "term.hpp"
#include <cctype>



namespace poly {

    /*==========================================================
     * Term I/O
     */

    std::istream &operator>>(std::istream &in, Term &term) {
        if (!in) return in;

        double coeff;
        unsigned int exp;
        bool varreq;

        // coefficient
        if (in >> coeff) {
            varreq = false;
        }
        else {
            varreq = true;
            in.clear();
            if (in >> '-') {
                coeff = -1;
            }
            else {
                in.clear();
                coeff = 1;
            }
        }

        // exponent
        if (in >> 'x') {
            if (in >> '^') {
                in >> exp;
            }
            else {
                in.clear();
                exp = 1;
            }
        }
        else {
            exp = 0;
            if (!varreq) {
                in.clear();
            }
        }

        term = { coeff, exp };
        return in;
    }

    std::ostream &operator<<(std::ostream &out, Term term) {
        if (term.coefficient == -1 && term.exponent != 0) {
            out << '-';
        }
        else if (term.coefficient != 1 || term.exponent == 0) {
            out << term.coefficient;
        }
        if (term.exponent != 0) {
            out << 'x';
            if (term.exponent != 1) {
                out << '^' << term.exponent;
            }
        }

        return out;
    }


    /*==========================================================
     * Input specific characters
     */

    std::istream &operator>>(std::istream &in, const char &expect) {
        if (!in) return in;

        while (std::isspace(in.peek())) in.ignore();

        if (in.peek() == expect) {
            in.get();
        }
        else {
            in.setstate(std::istream::failbit);
        }
        return in;
    }

}
