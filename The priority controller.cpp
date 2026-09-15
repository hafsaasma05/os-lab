#include <iostream>
#include <windows.h>
int main() {
    HANDLE process = GetCurrentProcess();
    if (SetPriorityClass(
        process,
        BELOW_NORMAL_PRIORITY_CLASS
    )) {
        std::cout << "Process priority changed successfully.\n";
    } else {
        std::cerr << "Could not change process priority.\n";
        return 1;
    }
    return 0;
}
