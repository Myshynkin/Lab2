#include "pch.h"

void value(int a) {
    a = 100;
}

void reference(int& a) {
    a = 100;
}

TEST(test1) {
    int a = 5;
    value(a);
    EXPECT_EQ(a, 5);
}

TEST(test2) {
    int a = 5;
    reference(a);
    EXPECT_EQ(a, 100); 
}
