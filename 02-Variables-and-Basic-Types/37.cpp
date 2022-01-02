#include <iostream>

int main() {
    int a = 3, b = 4;
    decltype(a) c = a; // int
    decltype(a = b) d = a; // int &
    std::cout << d << std::endl; // 3，只推断不求值
    return 0;
}