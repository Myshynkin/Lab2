#include "pch.h"
#include <iostream>
#include <windows.h>
#include <psapi.h>

class A {
public:
    A() {}

    ~A() {
    }
};
void Stack() {
    for (int i = 0; i <= 100; i++) {
        A a;
    }
}

void Heap() {
    for (int i = 0; i <= 100; i++) {
        A* a = new A();
    }
  

}


TEST(testheap) {
    HANDLE process = GetCurrentProcess();
    PROCESS_MEMORY_COUNTERS_EX memInfo;
    GetProcessMemoryInfo(process, (PROCESS_MEMORY_COUNTERS*)&memInfo, sizeof(memInfo));
    SIZE_T before = memInfo.PrivateUsage;
    Heap();
    GetProcessMemoryInfo(process, (PROCESS_MEMORY_COUNTERS*)&memInfo, sizeof(memInfo));
    SIZE_T after = memInfo.PrivateUsage;
    EXPECT_LT(before, after);
}
TEST(teststack) {
    HANDLE process = GetCurrentProcess();
    PROCESS_MEMORY_COUNTERS_EX memInfo;
    GetProcessMemoryInfo(process, (PROCESS_MEMORY_COUNTERS*)&memInfo, sizeof(memInfo));
    SIZE_T before = memInfo.PrivateUsage;
    Stack();
    GetProcessMemoryInfo(process, (PROCESS_MEMORY_COUNTERS*)&memInfo, sizeof(memInfo));
    SIZE_T after = memInfo.PrivateUsage;
    EXPECT_EQ(before, after);
}
