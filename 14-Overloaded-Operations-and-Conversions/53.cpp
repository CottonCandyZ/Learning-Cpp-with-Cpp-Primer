//
// Created by CottonCandyZ on 3/13/22.
//

#include <iostream>

class SmallInt {
    friend SmallInt operator+(const SmallInt &, const SmallInt &);

public:
    SmallInt(int i = 0) : val(i) {
        if (i < 0 || i > 255)
            throw std::out_of_range("Bad SmallInt value");
    }


    operator int() const { return val; }

private:
    std::size_t val;
};

int main() {
    SmallInt s1;
//    double d = s1 + 3.14;
//    double d = static_cast<int>(s1) + 3.14;
    double d = s1 + SmallInt(3.14);

    return 0;
}