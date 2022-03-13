//
// Created by CottonCandyZ on 3/13/22.
//

#include <iostream>
struct LongDouble {
    LongDouble(double = 0.0);
    operator double();
    operator float();
};

void calc(int) {
    std::cout << "call calc(int)" << std::endl;
};
void calc(LongDouble) {
    std::cout << "call calc(LongDouble)" << std::endl;
}

int main() {
    double dval;
    calc(dval); // 输出 call calc(int)
    return 0;
}