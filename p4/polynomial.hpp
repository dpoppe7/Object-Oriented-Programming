#ifndef POLY_START_POLYNOMIAL_HPP
#define POLY_START_POLYNOMIAL_HPP

#include "term.hpp"
#include <utility>

namespace poly {

    struct Node {
        Term term;
        Node *next;
    };

    class Polynomial {
    public:

        Polynomial() : head(nullptr) , p_degree(0) , exp(0){};

        ~Polynomial();

        void addTerm(Term term);

        unsigned int degree(){
            if (p_degree != 0)
                p_degree = head->term.exponent;
            return p_degree;
        }

        double coefficientFor(unsigned int exponent){
            Node *it = head;
            while (it){
                if (it->term.exponent == exponent){
                    exp = it->term.coefficient;
                    break;
                }
                it = it->next;
            }
            return exp;
        }

        void clear();

        //Helper Fucntions
        int countNodes() {
            Node* temp = head;
            int i = 0;
            while(temp != nullptr) {
                i++;
                temp = temp->next;
            }
            return i;
        }

        // Term I/O
        friend std::istream &operator>>(std::istream &is, Polynomial &p);
        friend std::ostream &operator<<(std::ostream &os, Polynomial p);

        //operators
        friend bool operator ==(const Polynomial& a, const Polynomial& b);
        friend bool operator !=(const Polynomial& a, const Polynomial& b);
        friend bool operator <(const Polynomial& a, const Polynomial& b);
        friend bool operator >(const Polynomial& a, const Polynomial& b);
        friend bool operator <=(const Polynomial& a, const Polynomial& b);
        friend bool operator >=(const Polynomial& a, const Polynomial& b);

        Polynomial( const Polynomial &p ){
            Node * p1 = 0;//current
            Node * p2 = 0;//next

            if( p.head == 0 )
                head = 0;

            else{
                head = new Node;
                head->term.exponent = p.head->term.exponent;
                head->term.coefficient = p.head->term.coefficient;

                p1 = head;
                p2 = p.head->next;
            }

            while( p2 ){
                p1->next = new Node;
                p1 = p1->next;
                p1->term.exponent = p2->term.exponent;
                p1->term.coefficient = p2->term.coefficient;

                p2 = p2->next;
            }
            p1 -> next = 0;
        }

        Polynomial& operator =(const Polynomial &p){
            if (this == &p) {
                return *this;
            }

            Polynomial temp(p);
            std::swap(temp.head, head);
            return *this;
        }

        /** Move constructor *//*
        Polynomial(Polynomial &&) : head(nullptr){};

        *//** Move-assignment operator *//*
        Polynomial& operator=(Polynomial && p){};*/


    private:
        unsigned int p_degree;
        double exp;
        Node *head;
    };

}

#endif //POLY_START_POLYNOMIAL_HPP