#include "gtest/gtest.h"
#include "polynomial.hpp"

class PlynomialTest : public ::testing::Test

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
        }
        else if (in.peek() == '-') {
            in.get();
            op = Op::Minus;
        }
        else {
            in.setstate(std::istream::failbit);
        }
        return in;
    }

    /*==========================================================
     * Node helpers
     *
     * You may keep these function as-is, or scavenge them to
     * create your own functions.
     */

    struct Node {
        Term term;
        Node* next;
    };

    // Recursive functions to print out nodes in polynomial
    void printNodes(std::ostream &out, Node *node) {
        if (node == nullptr) return;

        if (node->term.coefficient >= 0) {
            out << " + " << node->term;
        }
        else {
            out << " - " << -node->term;
        }
        printNodes(out, node->next);
    }

    // Print polynomial from head node
    void polyPrint(std::ostream &out, const Node *head) {
        if (head == nullptr) {
            out << "p(0)";
        }
        else {
            out << "p(" << head->term;
            printNodes(out, head->next);
            out << ')';
        }
    }

    // The polyScan function below requires you to have an insert function like this:
    void insertNode(Node*& node, Term t);

    // Reads a polynomial and returns the node list
    Node *polyScan(std::istream &in) {
        if (!in) return nullptr;

        Node *head = nullptr;
        Term t;
        if (in >> 'p' >> '(' >> t) {
            if (t.coefficient != 0) {
                insertNode(head, t);
            }

            Op op;
            bool good = true;
            while (good && in >> op) {
                if (in >> t) {
                    if (op == Op::Minus) {
                        insertNode(head, -t);
                    }
                    else {
                        insertNode(head, t);
                    }
                }
                else {
                    good = false;
                }
            }
            if (good) {
                in.clear();
                in >> ')';
            }
        }

        return head;
    }

}