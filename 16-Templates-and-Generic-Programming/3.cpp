//
// Created by CottonCandyZ on 3/16/22.
//

#include <iostream>
#include "../14-Overloaded-Operations-and-Conversions/Sales_data_11.h"
template <typename T> int compare(const T &v1, const T &v2) {
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

int main() {
    Sales_data data1, data2;
    std::cout << compare(data1, data2) << std::endl;
    return 0;
}