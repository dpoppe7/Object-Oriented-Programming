#include "rational.hpp"
#include <stdexcept>
#include <iostream>
#include <utility>

int Rational::doubleBase = 1000000;

Rational::Rational(){
    numerator = 0;
    denominator = 1;
    sign = Sign::Positive;
}

int Rational::gcf(int a, int b) const{
    if (a % b == 0)
        return b;
    else
        return gcf(b, a % b);
}

int Rational::gcd(int a, int b) const{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

//unary operator
Rational Rational::operator-(){
    //std::cout << numerator*(-1) << " " << denominator << std::endl;
    sign = Sign::Negative;
    return Rational(-numerator, denominator);
}

/*Rational::Rational(int i){   // explicit conversion constructor int to Rational
    numerator = i;
    denominator = 1;
    if (i >= 0)
        sign = Sign::Positive;
    else if (i < 0)
        sign = Sign::Negative;
}

Rational::operator double() const {       // convert a Rational to an double
    return (double) numerator/denominator;
}*/

Rational::Rational(int i){
    numerator = i;
    denominator = 1;
    if (i >= 0)
        sign = Sign::Positive;
    else if (i < 0)
        sign = Sign::Negative;
}
Rational::operator double() const{
    return (double) numerator/denominator;
}

Rational::Rational(double d) {
    int _gcf = gcf(d*doubleBase, doubleBase);
    numerator = d*doubleBase / _gcf;    //works for int only
    denominator = abs(doubleBase) / _gcf;

    if (d >= 0)
        sign = Sign::Positive;
    else if (d < 0)
        sign = Sign::Negative;
}

Rational::operator int() const{
    return (int) numerator/denominator;
}

Rational::Rational(int num, int den){
    if (den == 0){
        throw std::domain_error( "Denominator must be grater than 0, but got " + std::to_string( den ) );
    }
    else{
        //sign of the rational
        if ((num > 0 && den > 0) || (num < 0 && den < 0)) {
            sign = Sign::Positive;
        }
        else{
            sign = Sign::Negative;
            num = abs(num);   //works for int only
            den = abs(den);
        }

        //gcf
        int _gcf = gcf(num, den);
        num = num / _gcf;
        den = den / _gcf;

        numerator = num;
        denominator = den;
    }
}

void swap(Rational& a, Rational&b){
    std::swap(a.numerator, b.numerator);
    std::swap(a.denominator, b.denominator);
}

//copy constructor and assignment
Rational::Rational (Rational const& rational){
    //sign of the rational
    if ((rational.numerator > 0 && rational.denominator > 0) || (rational.numerator < 0 && rational.denominator < 0)) {
        sign = Sign::Positive;
    }
    else{
        sign = Sign::Negative;
    }
    int _gcf = gcf(rational.numerator, rational.denominator);

    numerator = abs(rational.numerator) / _gcf;     //works for int only
    denominator = abs(rational.denominator) / _gcf;
}
Rational& Rational::operator=(Rational const& rational){
    if (this != &rational) // prevent self-assignment
    {
        numerator = rational.numerator;
        denominator = rational.denominator;
    }
    return *this;
}

//move constructor and assignment
Rational::Rational (Rational&& rational) noexcept{
    if ((rational.numerator > 0 && rational.denominator > 0) || (rational.numerator < 0 && rational.denominator < 0)) {
        sign = Sign::Positive;
    }
    else{
        sign = Sign::Negative;
    }
    int _gcf = gcf(rational.numerator, rational.denominator);

    numerator = abs(rational.numerator) / _gcf;     //works for int only
    denominator = abs(rational.denominator) / _gcf;
}
Rational& Rational::operator=(Rational&& rational) noexcept{
    if (this != &rational) // prevent self-assignment
    {
        std::swap(numerator, rational.numerator);
        std::swap(denominator, rational.denominator);
    }
    return *this;
}

//comparison operators
bool operator==(const Rational& lhs, const Rational& rhs){
    return lhs.numerator == rhs.numerator && lhs.denominator == rhs.denominator;
}
/*bool Rational::operator==(Rational const& rational) const{
    return  numerator == rational.numerator && denominator == rational.denominator && sign == rational.sign;
}*/
bool Rational::operator!=(Rational const& rational) const{
    return  numerator != rational.numerator || denominator != rational.denominator || sign != rational.sign;
}
/*bool operator!=(const Rational& lhs, const Rational& rhs);
    return numerator != rational.numerator || denominator != rational.denominator || sign != rational.sign;
}*/

bool Rational::operator < (Rational const& rhs) const{
    return  rhs.numerator < numerator && rhs.denominator < numerator;
}

bool Rational::operator >=(Rational const& rhs) const{
    return rhs.numerator >= numerator && rhs.denominator >= denominator;
}

bool Rational::operator > (Rational const& rhs) const{
    return  rhs.numerator > numerator && rhs.denominator > denominator;
}

bool Rational::operator <=(Rational const& rhs) const{
    return  rhs.numerator <= numerator && rhs.denominator <= denominator;
}

//math OP
Rational Rational::operator +(Rational const& rhs) const{
    int den3 = gcd(rhs.denominator, denominator);
    den3 = (rhs.denominator * denominator) / den3;
    int num3 = (rhs.numerator)*(den3/rhs.denominator) + (numerator)*(den3/denominator);
    int _gcf = gcf(num3, den3);
    num3 /= _gcf;
    den3 /= _gcf;
    return Rational {num3, den3};
}
Rational Rational::operator -(Rational const& rhs) const{
    Rational rational;

    rational.numerator = (numerator*rhs.denominator)-(rhs.numerator*denominator);
    rational.denominator = denominator*rhs.denominator;
    int _gcf = gcf(rational.numerator, rational.denominator);
    rational.numerator /= _gcf;
    rational.denominator/= _gcf;
    return {rational.numerator, rational.denominator};
}
Rational Rational::operator *(Rational const& rhs) const{
    Rational result;
    result.numerator = numerator * rhs.numerator;
    result.denominator = denominator * rhs.denominator;
    int _gcf = gcf(result.numerator, result.denominator);

    result.numerator /= _gcf;
    result.denominator /= _gcf;
    return result;
}
Rational Rational::operator /(Rational const& rhs) const{
    if (rhs.numerator == 0 && rhs.denominator == 1) {
        throw std::domain_error("Denominator must be grater than 0, but got " + std::to_string(0));
    }
    else {
        Rational result;
        result.numerator = denominator * rhs.numerator;
        result.denominator = numerator * rhs.denominator;
        int _gcf = gcf(result.numerator, result.denominator);

        result.numerator /= _gcf;
        result.denominator /= _gcf;

        return result;
    }
}

//math assignment operators
Rational& Rational::operator +=(Rational const& rhs){
    int den3 = gcd(rhs.denominator, denominator);
    den3 = (rhs.denominator * denominator) / den3;
    int num3 = (rhs.numerator)*(den3/rhs.denominator) + (numerator)*(den3/denominator);
    int _gcf = gcf(num3, den3);
    this->numerator = num3/_gcf;
    this->denominator = den3/_gcf;
    return *this;
}
Rational& Rational::operator -=(Rational const& rhs){
    int new_n = (numerator*rhs.denominator)-(rhs.numerator*denominator);
    int new_d = denominator*rhs.denominator;
    int _gcf = gcf(new_n, new_d);
    this->numerator = new_n/_gcf;
    this->denominator = new_d/_gcf;
    return *this;
}
Rational& Rational::operator *=(Rational const& rhs){
    int new_n = numerator * rhs.numerator/gcd(numerator * rhs.numerator, denominator * rhs.denominator);
    denominator = denominator * rhs.denominator/gcd(numerator * rhs.numerator, denominator * rhs.denominator);
    numerator = new_n;
    return *this;
}
Rational& Rational::operator /=(Rational const& rhs){
    int new_n = denominator * rhs.numerator;
    denominator = numerator * rhs.denominator;
    int _gcf = gcf(new_n, denominator);

    numerator = denominator/_gcf;
    denominator = new_n/_gcf;
    return *this;
}


//i/o operators
std::ostream & operator << (std::ostream &out, const Rational &c){
    out << c.numerator << "/" << c.denominator;
    return out;
}
std::istream & operator >> (std::istream &in,  Rational &c){
    in >> c.numerator >> c.denominator;
    return in;
}