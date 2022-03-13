//
// Created by CottonCandyZ on 3/12/22.
//

#include <iostream>
#include <vector>
#include "CheckStringSize_2.h"

int main() {
    std::string temp;

    CheckStringSize check_1_9(1, 9);
    CheckStringSize check_over_10(10, std::numeric_limits<size_t>::max());

    unsigned size_1_to_9(0);
    unsigned size_over_10(0);

    while (std::cin >> temp) {
        if (check_1_9(temp)) ++size_1_to_9;
        if (check_over_10(temp)) ++size_over_10;
    }

    std::cout << "string with length between 1 to 9 appears " << size_1_to_9
              << (size_1_to_9 > 1 ? " times" : " time") << std::endl;
    std::cout << "string with length over 10 appears " << size_over_10
              << (size_over_10 > 1 ? " times" : " time") << std::endl;
    return 0;
}
