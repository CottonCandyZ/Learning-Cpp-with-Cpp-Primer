//
// Created by CottonCandyZ on 3/14/22.
//

#ifndef C__PRIMER_LIMIT_QUOTE_3_H
#define C__PRIMER_LIMIT_QUOTE_3_H

#include "Disc_quote_1.h"

class Limit_quote : Disc_quote {
public:
    Limit_quote() = default;

    Limit_quote(const std::string &, double, std::size_t, std::size_t, double);

    double net_price(std::size_t) const override;

    void debug() const override {
        std::cout << "max_qty: " << max_qty;
    }

private:
    std::size_t max_qty;
};

Limit_quote::Limit_quote(const std::string &book, double p, std::size_t qty, std::size_t max, double disc) :
        Disc_quote(book, p, qty, disc), max_qty(max) {}

double Limit_quote::net_price(std::size_t n) const {
    if (n > max_qty) return max_qty * (1 - discount) * price + (n - max_qty) * price;
    else if (n >= quantity) return n * (1 - discount) * price;
    else return n * price;
}


#endif //C__PRIMER_LIMIT_QUOTE_3_H
