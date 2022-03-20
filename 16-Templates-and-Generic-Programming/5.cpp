//
// Created by CottonCandyZ on 3/16/22.
//

#include <iostream>

template<typename T, unsigned N>
void print(const T (&arr)[N]) {
    for (auto elem: arr) {
        std::cout << elem << std::endl;
    }
}

int main() {
    int arr[5]{1, 2, 3, 4, 5};
    std::string arr_s[5]{"h", "e", "l", "l", "o"};
    print(arr);
    print(arr_s);
    return 0;
}