//
// Created by CottonCandyZ on 3/13/22.
//

struct LongDouble {
    LongDouble(double = 0.0);
    operator double();
    operator float();
};


int main() {
    LongDouble ldObj;
    int ex1 = ldObj; // 二义性，不可
    float ex2 = ldObj; // 精确匹配，可
    return 0;
}