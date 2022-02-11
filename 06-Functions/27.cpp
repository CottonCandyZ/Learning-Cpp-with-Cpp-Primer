//
// Created by CottonCandyZ on 1/31/22.
//

#include <iostream>

int sum_int(std::initializer_list<int> il) {
    int sum = 0;
    for (auto &i: il) {
        sum += i;
    }
    return sum;
}


int main() {
    std::cout << sum_int({1, 2, 3, 4, 5, 6}) << std::endl;
    return 0;
}