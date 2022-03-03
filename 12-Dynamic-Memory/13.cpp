//
// Created by CottonCandyZ on 3/1/22.
//


#include <iostream>

int main () {
    auto sp = std::make_shared<int>();
    auto p = sp.get();
    delete p;
}

