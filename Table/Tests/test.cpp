#include <gtest/gtest.h>
#include "../Tests/table.hpp"
#include <iostream>
using namespace std;
TEST(DefaultCtor, HasCorrectValue) {
    Table<int> t;
    EXPECT_EQ(t.numRows(), 0);
    EXPECT_EQ(t.numCols(), 0);
}

TEST(Constructor, HasCorrectValue) {
    Table<int> t(3, 2);
    EXPECT_EQ(t.numRows(), 3);
    EXPECT_EQ(t.numCols(), 2);
}

/*TEST(Copy, HasCorrectValue) {
    Table t(3, 5);
    Table u = t;
    t = u;
}*/



