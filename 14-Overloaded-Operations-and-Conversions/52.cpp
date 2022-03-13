//
// Created by CottonCandyZ on 3/13/22.
//

#include <iostream>

class SmallInt {
public:
    SmallInt(int i = 0) : val(i) {
        if (i < 0 || i > 255)
            throw std::out_of_range("Bad SmallInt value");
    }

    operator int() const { return val; }

private:
    std::size_t val;
};

struct LongDouble {
    LongDouble(double d = 0.0): dou(d) {}

    operator double();

    operator float();

    LongDouble operator+(const SmallInt &s) {
        std::cout << "call LongDouble operator+(const SmallInt &)" << std::endl;
        return dou + s;
    };
    double dou;
};
LongDouble operator+(LongDouble& i, double d) {
    std::cout << "call LongDouble operator+(const SmallInt &)" << std::endl;
    return i + d;
};

int main() {
    SmallInt si;
    LongDouble ld;
//    ld = si + ld; // 二义性
    ld = ld + si; // 用 LongDouble operator+(const SmallInt &);
    return 0;
}