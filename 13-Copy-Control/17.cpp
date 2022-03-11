//
// Created by CottonCandyZ on 3/5/22.
//

#include <iostream>

class numberedWithoutCopy {
    inline static unsigned current_num = 0;
public:
    numberedWithoutCopy() {
        mysn = ++current_num;
    }
    unsigned mysn;
};


class numbered {
    inline static unsigned current_num = 0;
public:
    numbered() {
        mysn = ++current_num;
    }

    numbered(const numbered &n) { mysn = ++current_num; }

    unsigned mysn;
};


void f(numberedWithoutCopy s) { std::cout << s.mysn << std::endl; }


void f_c(numbered s) { std::cout << s.mysn << std::endl; }

void f_const(const numbered &s) { std::cout << s.mysn << std::endl; }

int main() {
    {
        numberedWithoutCopy a, b = a, c = b;
        f(a); f(b); f(c);
    }
    {
        numbered a, b = a, c = b;
        f_c(a); f_c(b); f_c(c);
    }
    {
        numbered a, b = a, c = b;
        f_const(a); f_const(b); f_const(c);
    }
    return 0;
}