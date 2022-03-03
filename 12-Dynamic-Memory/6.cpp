//
// Created by CottonCandyZ on 2/28/22.
//

#include <iostream>
#include <vector>

std::vector<int> * vector_factory() {
    return new std::vector<int>;
}

std::vector<int> * read(std::vector<int> *vec) {
    int buf;
    while (std::cin >> buf) {
        vec->push_back(buf);
    }
    return vec;
}

std::vector<int> * print(std::vector<int> *vec) {
    for (const auto &item:*vec) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    return vec;
}


int main() {
    delete print(read(vector_factory()));
    return 0;
}