//
// Created by CottonCandyZ on 2/21/22.
//

#include <iostream>

int main() {
    int temp = 10;
    auto lam = [&temp]() -> bool {
        if (temp == 0)
            return true;
        else {
            temp--;
            return false;
        }

    };
    int times = 0;
    while (!lam()) {
        times++;
        std::cout << "after " << times << " times, temp is: "
                  << temp << std::endl;
    }
    return 0;
}