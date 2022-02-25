//
// Created by CottonCandyZ on 2/22/22.
//

#include <iostream>
#include "../01-start/Sales_item.h"
#include <vector>
#include <numeric>

bool compareIsbnSort(const Sales_item &s1, const Sales_item &s2) { // 名字冲突
    return s1.isbn() < s2.isbn();
}


int main() {
    Sales_item buf;
    std::vector<Sales_item> records;
    while (std::cin >> buf) {
        records.push_back(buf);
    }
    if (records.empty()) {
        std::cerr << "No Data?!" << std::endl;
        return -1;
    }

    std::sort(records.begin(), records.end(), compareIsbnSort);
    auto iter = records.cbegin();
    auto iter_end = records.cend(); // 暂存
    while (iter != iter_end) {
        auto end = std::find_if(iter, iter_end,
                  [iter](const Sales_item &i) { return iter->isbn() != i.isbn(); });
        std::cout << std::accumulate(iter, end, Sales_item(iter->isbn())) << std::endl;
        iter = end;
    }


    return 0;
}