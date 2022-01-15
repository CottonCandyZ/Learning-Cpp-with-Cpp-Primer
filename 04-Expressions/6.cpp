#include <iostream>

int main() {
    int input;
    std::cin >> input;
    std::cout << (input % 2 ? "奇数":"偶数") << std::endl;
    // 更佳方案
    std::cout << (input & 0x1 ? "奇数":"偶数") << std::endl;
    return 0;
}