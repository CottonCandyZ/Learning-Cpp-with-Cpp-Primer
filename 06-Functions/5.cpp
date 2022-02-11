#include <iostream>

int my_abs(const int &num) {
    return num > 0 ? num : -num;
}

int main() {
    int num;
    std::cin >> num;
    std::cout << my_abs(num) << std::endl;
    return  0;
}