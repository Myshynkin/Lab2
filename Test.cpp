//#include "pch.h"
//#include <gtest/gtest.h>
//#include <iostream>
//
//
//class A {
//public:
//    static int destructorsCalled;
//
//    A() {}
//    ~A() { ++destructorsCalled; }
//};
//
//int A::destructorsCalled = 0;
//
//void Stack() {
//    A a;
// 
//}
//
//void Heap() {
//    A* a = new A();
//
//}
//
//TEST(DestructorTest, TestStack) {
//    A::destructorsCalled = 0; // reset counter
//    Stack();
//    EXPECT_EQ(A::destructorsCalled, 1);
//}
//
//TEST(DestructorTest, TestHeap) {
//    A::destructorsCalled = 0; // reset counter
//    Heap();
//    EXPECT_EQ(A::destructorsCalled, 1);
//}
//
//int main(int argc, char** argv) {
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}