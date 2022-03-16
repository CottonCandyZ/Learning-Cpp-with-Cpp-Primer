//
// Created by CottonCandyZ on 3/15/22.
//

#include "Bulk_quote_6.h"
#include <vector>

int main() {
    std::vector<std::shared_ptr<Quote>> vec;
    vec.push_back(std::make_shared<Bulk_quote>("978-7-121-15535-2", 128, 10, .25));
    vec.push_back(std::make_shared<Bulk_quote>("7-121-02909-X", 58, 10, .25));
    double sum = 0;
    std::for_each(vec.begin(), vec.end(),
                  [&](const std::shared_ptr<Quote> &q) { sum += q->net_price(15); });
    std::cout << sum << std::endl;
    return 0;
}