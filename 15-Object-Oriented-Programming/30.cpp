//
// Created by CottonCandyZ on 3/15/22.
//

#include "Basket_1.h"

int main() {
    Basket basket;
    basket.add_item(Bulk_quote("978-7-121-15535-2", 128, 10, .25));
    basket.add_item(Bulk_quote("7-121-02909-X", 58, 2, .25));
    basket.add_item(Bulk_quote("7-121-02909-X", 58, 2, .25));
    basket.total_receipt(std::cout);

    return 0;
}