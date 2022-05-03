#include <gtest/gtest.h>
#include "../Tests/rational.hpp"
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

TEST(DefaultCtor, HasCorrectValue) {
    Rational r;
    EXPECT_EQ(r.num(), 0);
    EXPECT_EQ(r.den(), 1);
}

TEST(ValueCtor, HasCorrectValue) {
    Rational r(27, 72);
    EXPECT_EQ(r.num(), 3);
    EXPECT_EQ(r.den(), 8);
}

TEST(ValueCtor1, HasCorrectValue) {
    Rational r(14, -7);
    EXPECT_EQ(r.num(), 2);
    EXPECT_EQ(r.den(), 1);
}

TEST(ValueCtor2, HasCorrectValue) {
    EXPECT_THROW(Rational r(5,0);, std::domain_error);
}

TEST(ComparisonOp, HasCorrectValue) {
    Rational r1(14, -7);
    Rational r2(14, -7);
    EXPECT_TRUE(r1 == r2);
}

TEST(CopyCtr, HasCorrectValue) {
    Rational r1{3, 6};
    Rational r2 =  r1;
    EXPECT_EQ(r2.num(), 1);
    EXPECT_EQ(r2.den(), 2);
}

TEST(CopyAssig, HasCorrectValue) {
    Rational r1, r2;
    r2 = {4,8};
    r1 = r2;
    EXPECT_EQ(r2.num(), 1);
    EXPECT_EQ(r2.den(), 2);
    EXPECT_EQ(r1.num(), 1);
    EXPECT_EQ(r1.den(), 2);
}

TEST(MoveCtr, HasCorrectValue) {
    Rational r1;
    Rational r2 = std::move(r1);
    EXPECT_EQ(r2.num(), 0);
    EXPECT_EQ(r2.den(), 1);
}

TEST(MoveCtr2, HasCorrectValue) {
    std::vector<Rational> a = {{1,2}, {3, 4}};
    std::vector<Rational> b;
    b = std::move(a);
    EXPECT_EQ(b.size(), 2);
    EXPECT_EQ(a.size(), 0);
}

TEST(ConvertOp, HasCorrectValue) {
    /* implicit
     * Rational r = -5;
    EXPECT_EQ(r.num(), -5);
    EXPECT_EQ(r.den(), 1);

    double d = r;
    EXPECT_EQ(d, -5.0);*/
}

TEST(ConvertOp2, HasCorrectValue) {
    Rational r5(2);
    EXPECT_EQ(r5.num() , 2);
    EXPECT_EQ(r5.den() , 1);
}

TEST(ConvertOp3, HasCorrectValue) {
    Rational r5(20);
    double d = (double)r5;
    EXPECT_EQ(d, 20.0);
}

TEST(ConvertOp4, HasCorrectValue) {
    auto r = (Rational)3.33333;
    EXPECT_EQ(r.num() , 333333);
    EXPECT_EQ(r.den() , 100000);
}

TEST(CompOp1, HasCorrectValue) {
    Rational r{ 1, 2 };
    Rational q{ 2, 5 };
    bool b;
    b = r == q;  // b = false
    ASSERT_FALSE(b);
}

TEST(CompOp2, HasCorrectValue) {
    Rational r{ 1, 2 };
    Rational q{ 2, 5 };
    bool b;
    b = r > q;   // b = true
    ASSERT_TRUE(b);
}

TEST(CompOp3, HasCorrectValue) {
    Rational r{ 1, 2 };
    Rational q{ 2, 5 };
    bool b;
    b = r < q;   // b = true
    ASSERT_FALSE(b);
}

TEST(CompOp4, HasCorrectValue) {
    Rational r{ 1, 2 };
    Rational q{ 1, 2 };
    bool b;
    b = r <= q;   // b = true
    ASSERT_TRUE(b);
}

TEST(CompOp5, HasCorrectValue) {
    Rational r{ 2, 3 };
    Rational q{ 2, 3 };
    bool b;
    b = r >= q;   // b = true
    ASSERT_TRUE(b);
}

TEST(CompOp6, HasCorrectValue) {
    Rational r{ 1, 2 };
    Rational q{ 2, 5 };
    bool b;
    b = r != q;  // b = false
    ASSERT_TRUE(b);
}

TEST(MathOps, HasCorrectValue) {
    Rational r{ 3, 4 };
    Rational q{ 5, 6 };
    Rational p;
    p = q * r;
    EXPECT_EQ(p.num() , 5);
    EXPECT_EQ(p.den() , 8);
}

TEST(MathOps1, HasCorrectValue) {
    Rational r{ 3, 4 };
    Rational q{ 5, 6 };
    Rational p;
    p = q + r;
    EXPECT_EQ(p.num() , 19);
    EXPECT_EQ(p.den() , 12);
}

TEST(MathOps2, HasCorrectValue) {
    Rational r{ 3, 4 };
    Rational q{ 5, 6 };
    Rational p;
    p = q - r;
    EXPECT_EQ(p.num() , 1);
    EXPECT_EQ(p.den() , 12);
}

TEST(MathOps3, HasCorrectValue) {
    Rational r{ 3, 4 };
    Rational q{ 5, 6 };
    Rational p;
    p = q / r;
    EXPECT_EQ(p.num() , 9);
    EXPECT_EQ(p.den() , 10);
}

TEST(MathOps4, HasCorrectValue) {
    Rational r{ 3, 4 };
    Rational q{ 5, 6 };
    //EXPECT_THROW(Rational p = q / (r - r);, std::domain_error);
    Rational p;
    EXPECT_THROW(p = q / (r - r),std::domain_error);
}

TEST(MathOps5, HasCorrectValue) {
    Rational r{ 3, 4 };
    Rational p = -r;
    /*EXPECT_EQ(p.num(), -3);
    EXPECT_EQ(p.den() , 4);*/
}

/*TEST(IoOps, HasCorrectValue) {
    Rational r;
    std::cin >> r;

    // assume r is a Rational
    std::ostringstream out;
    out << r;
    EXPECT_EQ(out.str(), "3/4");
}*/

TEST(MathAssignOps, HasCorrectValue) {
    Rational r{ 3, 4 };
    Rational q{ 1, 3 };

    r *= q;      // r = 1/4
    EXPECT_EQ(r.num(), 1);
    EXPECT_EQ(r.den(), 4);
}

TEST(MathAssignOps1, HasCorrectValue) {
    Rational r{ 3, 4 };
    Rational q{ 1, 3 };

    r += q;
    EXPECT_EQ(r.num(), 13);
    EXPECT_EQ(r.den(), 12);
}

TEST(MathAssignOps2, HasCorrectValue) {
    Rational r{ 3, 4 };
    Rational q{ 1, 3 };

    r -= q;
    EXPECT_EQ(r.num(), 5);
    EXPECT_EQ(r.den(), 12);
}

TEST(Test, HasCorrectValue) {
    Rational r3(2, 3);
    //std::cout << r3.num() ;
}