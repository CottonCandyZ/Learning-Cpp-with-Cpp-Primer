//
// Created by CottonCandyZ on 2/19/22.
//

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vi;
    for (int i = 0; i < 1024; ++i) {
        vi.push_back(i);
        if (i % 8 == 0) {
            std::cout << "size: " << vi.size()
                      << ", capacity: " << vi.capacity() << std::endl;
        }
    }
    return 0;
}