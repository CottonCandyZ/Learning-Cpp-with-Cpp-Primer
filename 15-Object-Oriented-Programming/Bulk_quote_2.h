//
// Created by CottonCandyZ on 3/14/22.
//

#ifndef C__PRIMER_BULK_QUOTE_2_H
#define C__PRIMER_BULK_QUOTE_2_H

#include "Quote_2.h"

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;

    Bulk_quote(const std::string &, double, std::size_t, double);

    double net_price(std::size_t) const override;

    void debug() const override {
        std::cout << "min_qty: " << min_qty << "discount: " << discount;
    }

protected: // 考虑 5.7 要用到
    std::size_t min_qty = 0;
    double discount = 0.0;
};

Bulk_quote::Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) :
        Quote(book, p), min_qty(qty), discount(disc) {}

double Bulk_quote::net_price(std::size_t cnt) const {
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

#endif //C__PRIMER_BULK_QUOTE_2_H
