//
// Created by CottonCandyZ on 1/29/22.
//

#include <iostream>

int compare(const int num, const int * const p) {
    return (num > *p) ? num : *p;
}


int main() {
    int i = 0;
    std::cout << compare(10, &i) << std::endl;
}