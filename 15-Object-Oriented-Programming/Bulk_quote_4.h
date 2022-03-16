//
// Created by CottonCandyZ on 3/15/22.
//

#ifndef C__PRIMER_BULK_QUOTE_4_H
#define C__PRIMER_BULK_QUOTE_4_H

#include "Disc_quote_2.h"

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


#endif //C__PRIMER_BULK_QUOTE_4_H
