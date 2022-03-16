//
// Created by CottonCandyZ on 3/14/22.
//

#ifndef C__PRIMER_BULK_QUOTE_3_H
#define C__PRIMER_BULK_QUOTE_3_H

#include "Disc_quote_1.h"

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double price, std::size_t qty, double disc) :
    Disc_quote(book, price, qty, disc) {}
    double net_price(std::size_t) const override;
};

double Bulk_quote::net_price(std::size_t n) const {
    if (n >= quantity)
        return n * (1 - discount) * price;
    else
        return n * price;
}


#endif //C__PRIMER_BULK_QUOTE_3_H
