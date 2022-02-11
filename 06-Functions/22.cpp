//
// Created by CottonCandyZ on 1/29/22.
//

#include <iostream>

void ex_pointer(int *&p1, int *&p2) { // 指针的引用
    int *temp = p1;
    p1 = p2;
    p2 = temp;
}


int main() {
    int i = 1, j = 2;
    int *p1 = &i, *p2 = &j;
    ex_pointer(p1, p2);
    std::cout << *p1 << std::endl << *p2;
    return 0;
}