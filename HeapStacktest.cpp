#include "pch.h"
#include <iostream>

class A {
public:
    static int numbofdestructorcalls;

    A() {}

    ~A() {
        numbofdestructorcalls++;
    }
};

int A::numbofdestructorcalls = 0;

void Stack() {
    A a;
}

void Heap() {
    A* a = new A();
}

TEST(teststack) {
    A::numbofdestructorcalls = 0;
    Stack();
    EXPECT_EQ(A::numbofdestructorcalls, 1);
}

TEST(testheap) {
    A::numbofdestructorcalls = 0;
    Heap();
    EXPECT_EQ(A::numbofdestructorcalls, 0);
}