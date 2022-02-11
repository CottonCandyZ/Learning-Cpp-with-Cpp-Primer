//
// Created by CottonCandyZ on 1/19/22.
//

#include <iostream>
#include "../Chapter6.h"

int main() {
    try {
        input_num();
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}