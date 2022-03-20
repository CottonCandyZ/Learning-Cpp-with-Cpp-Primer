//
// Created by CottonCandyZ on 3/16/22.
//

#include <iostream>
template <typename T, unsigned N> T * begin(T (&arr)[N]) {
    return arr;
}

template <typename T, unsigned N> T * end(T (&arr)[N]) {
    return arr + N;
}

int main() {
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    for (auto t = begin(arr); t != end(arr); ++t) {
        std::cout << *t << std::endl;
    }
    return 0;
}