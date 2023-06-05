#include "pch.h"
#include <iostream>
#include <cstdlib>

int count = 0;
const int max = 40;

void* operator new(size_t size) {
    count++;
    return malloc(size);
}

void operator delete(void* memory) noexcept {
    count--;
    free(memory);
}

TEST(MemoryLeaktest) {
    count = 0;
    for (int i = 0; i < max + 1; ++i) {
        int* a = new int;
        if (count > max) {
            FAIL() << "Memoryleaktest";
        }
    }
}
