#include <iostream>

int main() {
    int first, second;
    std::cin >> first >> second;
    std::cout << "The product of ";
    std::cout << first;
    std::cout << " and ";
    std::cout << second;
    std::cout << " is ";
    std::cout << first * second;
    std::cout << std::endl;
    return 0;
}