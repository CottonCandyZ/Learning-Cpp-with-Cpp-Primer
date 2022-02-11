//
// Created by CottonCandyZ on 1/19/22.
//

#include <iostream>

void ex_numbers(int *num_1, int *num_2) {
    int temp;
    temp = *num_1;
    *num_1  = *num_2;
    *num_2 = temp;
}

int main() {
    int num_1 = 1, num_2 = 2;
    ex_numbers(&num_1, &num_2);
    std::cout << num_1 << " " << num_2 << std::endl;
    return 0;
}