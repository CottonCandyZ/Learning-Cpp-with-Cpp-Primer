#include <iostream>
int main() {
    int start, end;
    std::cin >> start >> end;
    if (start < end) {
        while (start <= end) {
            std::cout << start++ << " ";
        }
    } else {
        while (start >= end) {
            std::cout << start-- << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}