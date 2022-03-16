//
// Created by CottonCandyZ on 3/15/22.
//

#ifndef C__PRIMER_BULK_QUOTE_6_H
#define C__PRIMER_BULK_QUOTE_6_H

#include "Disc_quote_1.h"

class Bulk_quote : public Disc_quote {
public:
    using Disc_quote::Disc_quote;
    double net_price(std::size_t) const override;
};

double Bulk_quote::net_price(std::size_t n) const {
    if (n >= quantity)
        return n * (1 - discount) * price;
    else
        return n * price;
}


#endif //C__PRIMER_BULK_QUOTE_6_H
