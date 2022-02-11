//
// Created by CottonCandyZ on 2/11/22.
//

#include <iostream>
#include <vector>

int plus(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

int main() {
    std::vector<decltype(plus) *> vec;
    vec.push_back(plus);
    vec.push_back(sub);
    vec.push_back(mul);
    vec.push_back(divide);
    for (auto &item: vec) {
        std::cout << item(3, 2) << std::endl;
    }
    return 0;
}