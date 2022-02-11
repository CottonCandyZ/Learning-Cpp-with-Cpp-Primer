//
// Created by CottonCandyZ on 1/29/22.
//

#include <iostream>

void print(const int *begin, const int *end) {
    while (begin != end) {
        std::cout << *begin++ << std::endl;
    }
}

void print(const int &i) {
    std::cout << i << std::endl;
}

int main() {
    int i = 0, j[2] = {0, 1};
    print(std::begin(j), std::end(j));
    print(i);
    return 0;
}