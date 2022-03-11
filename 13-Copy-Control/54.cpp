//
// Created by CottonCandyZ on 3/11/22.
//


#include "HasPtr_9.h"

int main() {
    HasPtr hp("Hello");
    HasPtr h2("Hello");
    hp = std::move(h2);

    return 0;
}