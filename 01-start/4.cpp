#include <iostream>

int main() {
    int first, second;
    std::cin >> first >> second;
    std::cout << "The product of " << first
              << " and " << second << " is "
              << first * second << std::endl;
    return 0;
}