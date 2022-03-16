//
// Created by CottonCandyZ on 3/15/22.
//

#include "Bulk_quote_5.h"

int main() {
    Quote quote("C++ Primer", 128);
    Bulk_quote bulkQuote("C++ Primer", 128, 2, 0.2);
    Bulk_quote t = std::move(bulkQuote);
    Bulk_quote p = t;
    t = p;
    Quote &q = t;
    return 0;
}