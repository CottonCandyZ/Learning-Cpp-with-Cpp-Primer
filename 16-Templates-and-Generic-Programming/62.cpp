//
// Created by CottonCandyZ on 3/20/22.
//

#include <iostream>
#include "Sales_data_12.h"
#include <unordered_set>

namespace std {
    template<>
    struct hash<Sales_data> {
        typedef size_t result_type;
        typedef Sales_data argument_type;

        size_t operator()(const Sales_data &s) const;
    };

    size_t hash<Sales_data>::operator()(const Sales_data &s) const {
        std::cout << "hash<Sales_data>::operator()" << std::endl;
        return hash<string>()(s.bookNo) ^
               hash<unsigned>()(s.units_sold) ^
               hash<unsigned>()(s.revenue);
    }
}

int main() {
    std::unordered_set<Sales_data> SDest;
    SDest.emplace("978-7-121-15535-2", 1, 1);
    return 0;
}