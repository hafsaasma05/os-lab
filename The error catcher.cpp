#include <iostream>
#include <cstdio>
int main() {
    FILE* file = std::fopen("ghost.txt", "r");
    if (file == nullptr) {
        std::perror("Failed to open file");
        return 1;
    }
    std::fclose(file);
    return 0;
}