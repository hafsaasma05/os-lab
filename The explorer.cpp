#include <iostream>
#include <cstdlib>
int main() {
    int result = std::system("dir");
    if (result != 0) {
        std::cerr << "The dir command failed.\n";
        return 1;
    }
    return 0;
}	