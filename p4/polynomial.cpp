#include "polynomial.hpp"
#include <string>
#include <map>
#include <iostream>

namespace poly {

    /*==========================================================
     * Input plus/minus operator.
     */

    // Input plus/minus operator
    enum class Op {
        Plus, Minus
    };

    std::istream &operator>>(std::istream &in, Op &op) {
        if (!in) return in;
        while (std::isspace(in.peek())) in.ignore();
        if (in.peek() == '+') {
            in.get();
            op = Op::Plus;
        } else if (in.peek() == '-') {
            in.get();
            op = Op::Minus;
        } else {
            in.setstate(std::istream::failbit);
        }
        return in;
    }


    //std::istream &operator>>(std::istream &is, Polynomial &term);
    //std::ostream &operator<<(std::ostream &os, Polynomial t);
    /*==========================================================
     * Node helpers
     *
     * You may keep these function as-is, or scavenge them to
     * create your own functions.
     */


    // Recursive functions to print out nodes in polynomial
    void printNodes(std::ostream &out, Node *node) {
        if (node == nullptr) return;

        if (node->term.coefficient >= 0) {
            out << " + " << node->term;
        } else {
            out << " - " << -node->term;
        }
        printNodes(out, node->next);
    }

    // Print polynomial from head node
    void polyPrint(std::ostream &out, const Node *head) {
        if (head == nullptr) {
            out << "p(0)";
        } else {
            out << "p(" << head->term;
            printNodes(out, head->next);
            out << ')';
        }
    }

    void deleteNode(Node *&node) {
        Node *tempNode = node;
        node = node->next;
        delete node;
    }

    // The polyScan function below requires you to have an insert function like this:
    void insertNode(Node *&node, Term term) {
        if (node == nullptr) {
            node = new Node{term, nullptr};
        } else {
            if (term.exponent > node->term.exponent) {
                node = new Node{term, node};
            } else if (term.exponent == node->term.exponent) {
                node->term.coefficient += term.coefficient;
                if (node->term.coefficient == 0) {
                    deleteNode(node);
                }
            } else {   //less than
                insertNode(node->next, term);
            }
        }
    }

    // Reads a polynomial and returns the node list
    Node *polyScan(std::istream &in) {
        if (!in) return nullptr;

        Node *head = nullptr;
        if (!(in >> 'p' >> '(')) {
            //printf("Error: Could not read p(");
            return nullptr;
        }
        while(true){
            if (in.peek() == ')') {
                in.get();
                break;
            }

            //Reads: 5x^2 || x^2 || -3x || +3x
            Op op;
            if (!(in >> op)){
                op = Op::Plus;
                in.clear();
            }

            Term t;
            in >> t;
            if (op == Op::Minus){
                t = -t;
            }

            //2x^2+4x+8
            Node *node = new Node{t, nullptr};
            if (head == nullptr){
                head = node;
            }
            else{
                insertNode(head, t);
            }
        }
        return head;
    }


    //I/O Operators for a Polynomial
    std::istream &operator>>(std::istream &in, Polynomial &p) {
        p.head = polyScan(in);
        return in;
    }

    std::ostream &operator<<(std::ostream &os, Polynomial p){
        polyPrint(os, p.head);
        return os;
    }

    //Comparison Operators
    bool operator ==(const Polynomial& a, const Polynomial& b) {
        Node* ptr_1 = a.head;
        Node* ptr_2 = b.head;

        while (ptr_1 && ptr_2){
            if (ptr_1->term.coefficient != ptr_2->term.coefficient) return false;
            if (ptr_1->term.exponent != ptr_2->term.exponent) return false;

            ptr_1 = ptr_1->next;
            ptr_2 = ptr_2->next;
        }
        return true;
    }

    bool operator !=(const Polynomial& a, const Polynomial& b) {
        return !(a == b);
    }

    bool operator <(const Polynomial& a, const Polynomial& b){
        Node* ptr_1 = a.head;
        Node* ptr_2 = b.head;

        if (a == b) return false;

        while (ptr_1 && ptr_2) {
            if (ptr_1->term.exponent < ptr_2->term.exponent) {
                return true;
            } else if (ptr_1->term.exponent == ptr_2->term.exponent) {

                if (ptr_1->term.coefficient < ptr_2->term.coefficient) {
                    return true;
                }
                else if (ptr_1->term.coefficient == ptr_2->term.coefficient){
                        ptr_1 = ptr_1->next;
                        ptr_2 = ptr_2->next;
                }
                else{ // >
                    return false;
                }
            }
            else{ //>
                return false;
            }
        }
        return false;
    }

    bool operator >(const Polynomial& a, const Polynomial& b){
        if (a == b) return false;
        return !(a < b);
    }

    bool operator <=(const Polynomial& a, const Polynomial& b){
        return (a < b || a == b);
    }

    bool operator >=(const Polynomial& a, const Polynomial& b){
        return (a > b || a == b);
    }

    Polynomial::~Polynomial(){
        /*Node *nodePtr;
        Node *nextNode;

        nodePtr = head;

        while (nodePtr){
            nextNode = nodePtr->next;
            delete nodePtr;
            nodePtr = nextNode;
        }*/
    }



    //Polynomial class methods
    void Polynomial::addTerm(Term term){
        insertNode(head, term);
    }


    void deleteNodes(Node* node){
        if (node != nullptr){
            deleteNodes(node->next);
            delete node;
        }
    }

    void Polynomial::clear(){
        deleteNodes(head);
    }


}