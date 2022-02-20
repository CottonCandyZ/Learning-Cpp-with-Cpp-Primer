//
// Created by CottonCandyZ on 2/18/22.
//

#include <iostream>
#include <vector>

int main() {
    std::vector<int> empty_vec;
//    try {
        std::cout << empty_vec.at(0); // terminating with uncaught exception of type std::out_of_range: vector
        std::cout << empty_vec[0]; //interrupted by signal 11: SIGSEGV
        std::cout << empty_vec.front(); // interrupted by signal 11: SIGSEGV
        std::cout << *empty_vec.begin(); // interrupted by signal 11: SIGSEGV
        std::cout << std::endl;
//    } catch (std::exception &e) {
//        std::cerr << e.what() << std::endl;
//    }

    return 0;
}