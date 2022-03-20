//
// Created by CottonCandyZ on 3/17/22.
//

#include <iostream>
#include "Blob_3.h"

int main() {
    Blob<int> blob{1,2,3};
    for (size_t i = 0; i != blob.size(); ++i) {
        std::cout << blob[i] << std::endl;
    }
    return 0;
}