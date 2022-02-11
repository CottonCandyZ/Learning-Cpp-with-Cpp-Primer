//
// Created by CottonCandyZ on 1/19/22.
//

#include <iostream>
#include "../Chapter6.h"

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
