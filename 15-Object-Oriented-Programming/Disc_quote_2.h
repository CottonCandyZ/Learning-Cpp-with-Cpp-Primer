//
// Created by CottonCandyZ on 3/15/22.
//

#ifndef C__PRIMER_DISC_QUOTE_2_H
#define C__PRIMER_DISC_QUOTE_2_H

#include "Quote_2.h"

class Disc_quote : public Quote {
public:
    Disc_quote(const std::string &book, double price, std::size_t qty, double disc) :
        Quote(book, price), quantity(qty), discount(disc) { }
        double net_price(std::size_t) const = 0;

protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

#endif //C__PRIMER_DISC_QUOTE_2_H
