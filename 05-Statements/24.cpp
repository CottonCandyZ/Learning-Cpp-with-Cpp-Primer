#include <iostream>

int main() {
    int num_1, num_2;
    std::cin >> num_1 >> num_2;
    if (num_2 == 0) throw std::runtime_error("尝试除以 0");
    std::cout << num_1 / num_2 << std::endl;
    return 0;
}