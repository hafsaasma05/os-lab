#include <iostream>
#include <windows.h>
int main() {
    HANDLE readPipe;
    HANDLE writePipe;
    if (!CreatePipe(
        &readPipe,
        &writePipe,
        nullptr,
        0
    )) {
        std::cerr << "Failed to create pipe.\n";
        return 1;
    }
    const char message[] = "Hello through the pipe!";
    DWORD written = 0;
    DWORD read = 0;
    char buffer[100] = {};
    if (!WriteFile(
        writePipe,
        message,
        sizeof(message),
        &written,
        nullptr
    )) {
        std::cerr << "Failed to write to pipe.\n";
        CloseHandle(readPipe);
        CloseHandle(writePipe);
        return 1;
    }
    if (!ReadFile(
        readPipe,
        buffer,
        sizeof(buffer) - 1,
        &read,
        nullptr
    )) {
        std::cerr << "Failed to read from pipe.\n";
        CloseHandle(readPipe);
        CloseHandle(writePipe);
        return 1;
    }
    buffer[read] = '\0';
    std::cout << buffer << "\n";
    CloseHandle(readPipe);
    CloseHandle(writePipe);
    return 0;
}