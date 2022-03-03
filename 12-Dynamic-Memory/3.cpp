//
// Created by CottonCandyZ on 2/28/22.
//

// test Class StrBlob

#include <iostream>
#include "StrBlob_1.h"

int main() {
    const StrBlob test({"hello"});
    test.back() = "h";
    std::cout << test.back() << std::endl;
    return 0;
}