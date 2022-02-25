//
// Created by CottonCandyZ on 2/21/22.
//

#include <iostream>
#include "../07-Classes/Sales_data_6.h"
#include <vector>

bool compareIsbn(const Sales_data &s1, const Sales_data &s2) {
    return s1.isbn() < s2.isbn();
}


int main() {
    std::vector<Sales_data> vec_sd;
    Sales_data buf;
    while(read(std::cin, buf)) {
        vec_sd.push_back(buf);
    }
    std::stable_sort(vec_sd.begin(), vec_sd.end(), compareIsbn);
    for (const auto &item: vec_sd) {
        print(std::cout, item) << std::endl;
    }
    return 0;
}