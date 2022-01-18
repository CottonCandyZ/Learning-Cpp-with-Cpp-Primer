#include <iostream>

int main() {
    int num_1, num_2;
    while (std::cin >> num_1 >> num_2) {
        try {
            if (num_2 == 0) throw std::runtime_error("尝试除以 0");
            std::cout << num_1 / num_2 << std::endl;
            break;
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
            std::cout << "是否重新输入？y or n" << std::endl;
            char c;
            std::cin >> c;
            if (!std::cin || c == 'n')
                break;
        }
    }
    return 0;
}