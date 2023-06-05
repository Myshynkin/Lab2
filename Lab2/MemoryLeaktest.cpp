#include "pch.h"
#include <windows.h>
#include <psapi.h>

SIZE_T GetTotalMemory() {
    PROCESS_MEMORY_COUNTERS_EX pmc;
    GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
    return pmc.PrivateUsage;
}

void MemoryLeakingFunction() {
    for (int i = 0; i <= 1000; i++) {
        int* a = new int;
    }
}
TEST(MemoryLeakTest)
{
        SIZE_T memoryBefore;
        SIZE_T memoryAfter;
    for (int i = 0; i <= 5; i++) {
        memoryBefore = GetTotalMemory();
        MemoryLeakingFunction();
        memoryAfter = GetTotalMemory();
        EXPECT_LT(memoryBefore, memoryAfter);
    }
}
