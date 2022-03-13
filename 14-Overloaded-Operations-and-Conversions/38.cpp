//
// Created by CottonCandyZ on 3/12/22.
//

#include <iostream>
#include <vector>

int main() {
    std::vector<int> time_appears(11);
    std::string temp;

    while (std::cin >> temp) {
        size_t size = temp.size();
        if (size > 0 && size < 11) {
            ++time_appears[size];
        }
    }
    for (int i = 1; i < 11; ++i) {
        std::cout << "string with length of " << i << " appears " << time_appears[i]
                  << (time_appears[i] > 1 ? " times" : " time") << std::endl;
    }
    return 0;
}
