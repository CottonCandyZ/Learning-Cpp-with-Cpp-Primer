//
// Created by CottonCandyZ on 3/20/22.
//

#include <iostream>
#include <vector>

template<typename T>
size_t count(const std::vector<T> &vec, const T &t) {
    return std::count(vec.begin(), vec.end(), t);
}

int main() {
    std::vector<double> v_d{1, 2.5, 2, 2.5, 5, 6};
    std::vector<int> v_i{1, 2, 2, 2, 5, 6};
    std::vector<std::string> v_s{"a", "a", "c"};
    std::cout << count(v_d, 2.5) << std::endl;
    std::cout << count(v_i, 2) << std::endl;
    std::cout << count(v_s, std::string("a")) << std::endl;

    return 0;
}