//
// Created by CottonCandyZ on 3/17/22.
//

#include <iostream>
#include "UniquePtr_1.h"
#include "SharedPtr_1.h"
#include "DebugDelete_1.h"

int main() {
    UniquePtr<int, DebugDelete> i_u(new int(1), DebugDelete());
    SharedPtr<int> i_s(new int(1), [](const int *t) {
        std::cout << "deleted" << std::endl;
        delete t;
    });
    return 0;
}