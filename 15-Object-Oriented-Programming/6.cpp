//
// Created by CottonCandyZ on 3/14/22.
//

#include "Bulk_quote_1.h"

int main() {
    Quote quote("C++ Primer", 128);
    Bulk_quote bulkQuote("C++ Primer", 128, 2, 0.2);
    print_total(std::cout, quote, 2);
    print_total(std::cout, bulkQuote, 2);
    return 0;
}