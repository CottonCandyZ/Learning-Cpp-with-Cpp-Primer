//
// Created by CottonCandyZ on 3/1/22.
//

#include <iostream>

void process(std::shared_ptr<int> ptr) {
    std::cout << ptr.use_count() << std::endl;
}


int main() {
    std::shared_ptr<int> p(new int(42));
    process(std::shared_ptr<int>(p));
    std::cout << p.use_count() << std::endl;
    return 0;
}