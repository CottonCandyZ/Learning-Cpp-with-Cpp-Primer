//
// Created by CottonCandyZ on 3/20/22.
//

#include <iostream>
#include <vector>

template<typename T>
size_t count(const std::vector<T> &vec, const T &t) {
    return std::count(vec.begin(), vec.end(), t);
}

template<>
size_t count(const std::vector<const char *> &vec, const char *const &t) {
    return std::count(vec.begin(), vec.end(), t);
}

int main() {
    std::vector<const char *> v_c{"hello", "boy"};
    const char *t = "boy";
    std::cout << count(v_c, t) << std::endl;
    return 0;
}