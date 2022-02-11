#include <iostream>

int fact(int val) {
    if (val == 1)
        return 1;
    else
        return val * fact(val - 1);
}

void input_num() {
    int num;
    std::cin >> num;
    if (num < 0) {
        throw std::runtime_error("数字需要大于 0");
    }
    std::cout << num << "! =  " << fact(num) << std::endl;
}

int main() {
    try {
        input_num();
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}