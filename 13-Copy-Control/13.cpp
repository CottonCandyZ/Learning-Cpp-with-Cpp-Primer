//
// Created by CottonCandyZ on 3/5/22.
//

#include <iostream>
#include <vector>

struct X {
    X() { std::cout << "X()" << std::endl; } // 构造函数

    X(const X &) { std::cout << "X(const X&)" << std::endl; } // 拷贝构造

    X &operator=(const X &) {
        std::cout << "X &operator=(const X&)" << std::endl;
        return *this;
    }

    ~X() { std::cout << "~X()" << std::endl; }
};

X func(const X& x) {
    return x;
}

void print(const std::string &s) {
    std::cout << "before " <<  s << std::endl;
}


int main() {
    print("X x1");
    X x1;
    print("X x2 = x1");
    X x2 = x1;
    print("X x3(x2)");
    X x3(x2);
    print("func(x1)");
    func(x1);
    print("x3 = x1");
    x3 = x1;
    print("std::vector<X> {x1, X()}");
    std::vector<X> v{x1, X()};
    print("v.reserve(2)");
    v.reserve(2);
    print("v.push_back(x2)");
    v.push_back(x3);
    print("return 0");
    return 0;
}