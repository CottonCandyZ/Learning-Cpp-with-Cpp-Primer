#include <iostream>

int fact(int val) {
    
    if (val == 1) return 1;
    else return val * fact(val - 1);
}

int main() {
    int num;
    std::cin >> num;
    if (num < 0) {
        std::cout << "数字需要大于 0" << std::endl;
        return -1;
    }
    std::cout << num  << "! =  "<<  fact(num) << std::endl;
    return 0;
}