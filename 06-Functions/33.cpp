//
// Created by CottonCandyZ on 2/10/22.
//
#include <iostream>
#include <vector>


void print(std::vector<int> &vec) {
    if (!vec.empty()) {
        auto temp = vec.back();
        vec.pop_back();
        print(vec);
        std::cout << temp << std::endl;
    }


}


int main() {
    std::vector<int> v{1, 2, 3, 4, 5};
    print(v);
    return 0;
}