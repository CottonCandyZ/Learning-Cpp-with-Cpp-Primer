//
// Created by CottonCandyZ on 2/28/22.
//

#include <iostream>
#include <vector>

std::shared_ptr<std::vector<int>> vector_factory() {
    return std::make_shared<std::vector<int>>();
}

std::shared_ptr<std::vector<int>> read(std::shared_ptr<std::vector<int>> vec) {
    int buf;
    while (std::cin >> buf) {
        vec->push_back(buf);
    }
    return vec;
}

std::shared_ptr<std::vector<int>> print(std::shared_ptr<std::vector<int>> vec) {
    for (const auto &item: *vec) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    return vec;
}


int main() {
    print(read(vector_factory()));
    return 0;
}