//
// Created by CottonCandyZ on 2/26/22.
//

#include <string>
#include <set>
#include "../07-Classes/Sales_data_7.h"

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() < rhs.isbn();
}


int main() {
    std::multiset<Sales_data, bool (*)(const Sales_data &lhs, const Sales_data &rhs)> bookstore(compareIsbn);
    return 0;
}