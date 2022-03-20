//
// Created by CottonCandyZ on 3/16/22.
//

#include <iostream>
template<typename T, unsigned N>
constexpr unsigned len(const T (&arr)[N]) {
    return N;
}

int main() {
    int arr[10];
    std::cout << len(arr) << std::endl;
    return 0;
}