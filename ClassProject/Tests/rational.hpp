#ifndef CLASSPROJECT_RATIONAL_HPP
#define CLASSPROJECT_RATIONAL_HPP
#include <string>
#include <vector>
#include <stdexcept>

enum class Sign{
    Positive,
    Negative,
};

class Rational {
    int numerator, denominator;
    Sign sign;
public:
    Rational();
    Rational(int n, int d);
    int gcf(int a, int b) const;

    int gcd(int a, int b) const;

    //getters
    int num(){return numerator;};
    int den(){return denominator;};

    //setters
    void num(int x){numerator = x;};
    void den(int x){
        if (x == 0)
            throw std::domain_error( "Denominator must be grater than 0, but got " + std::to_string( x ) );
        else
            denominator = x;
    };

    static int doubleBase;

    //conversions
    /*Rational(int i);               // implicit conversion constructor converts int to Rational
    operator double() const;       // implicit convert a Rational to an double*/

    explicit Rational(int i);
    explicit operator double() const;

    explicit Rational(double i);
    explicit operator int() const;

    //unary operator
    Rational operator-();

    //swap
    friend void swap(Rational& a, Rational&b);

    //copy constructor and assignment
    Rational (Rational const& rational);
    Rational& operator=(Rational const& rational);
    
    //move constructor and assignment
    Rational (Rational&& rational) noexcept;
    Rational& operator=(Rational&& rational) noexcept;


    //comparison operators
    friend bool operator==(const Rational& lhs, const Rational& rhs);
    //friend bool operator!=(const Rational& lhs, const Rational& rhs);
    //bool operator==(Rational const& rational) const;
    bool operator!=(Rational const& rational) const;

    bool operator < (Rational const& rhs) const;
    bool operator >=(Rational const& rhs) const;
    bool operator > (Rational const& rhs) const;
    bool operator <=(Rational const& rhs) const;

    //math OP
    Rational operator +(Rational const& rhs) const;
    Rational operator -(Rational const& rhs) const;
    Rational operator *(Rational const& rhs) const;
    Rational operator /(Rational const& rhs) const;

    // unary operators
    //Rational operator -() const;

    //math assignment operators
    Rational& operator +=(Rational const& src);
    Rational& operator -=(Rational const& src);
    Rational& operator *=(Rational const& src);
    Rational& operator /=(Rational const& src);

    //i/o
    friend std::ostream & operator << (std::ostream &out, const Rational &c);
    friend std::istream & operator >> (std::istream &in,  Rational &c);
};

#endif //CLASSPROJECT_RATIONAL_HPP
