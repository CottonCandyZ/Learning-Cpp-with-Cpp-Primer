//
// Created by CottonCandyZ on 3/15/22.
//

#ifndef C__PRIMER_BULK_QUOTE_5_H
#define C__PRIMER_BULK_QUOTE_5_H

#include "Quote_3.h"

class Bulk_quote : public Quote {
public:
    Bulk_quote() {
        std::cout << "Bulk_quote()" << std::endl;
    }

    Bulk_quote(const std::string &, double, std::size_t, double);

    Bulk_quote &operator=(const Bulk_quote &b) {
        Quote::operator=(b);
        min_qty = b.min_qty;
        discount = b.discount;
        std::cout << "Bulk_quote &operator=(const Bulk_quote &b)" << std::endl;
        return *this;
    }

    Bulk_quote &operator=(Bulk_quote &&b) noexcept {
        Quote::operator=(std::move(b));
        min_qty = std::move(b.min_qty);
        discount = std::move(b.discount);
        std::cout << "Bulk_quote &operator=(Bulk_quote &&b) noexcept" << std::endl;
        return *this;
    }

    Bulk_quote(const Bulk_quote &b) : Quote(b) {
        min_qty = b.min_qty;
        discount = b.discount;
        std::cout << "Bulk_quote(const Bulk_quote &b)" << std::endl;
    }

    Bulk_quote(Bulk_quote &&b) noexcept: Quote(std::move(b)) {
        min_qty = std::move(b.min_qty);
        discount = std::move(b.discount);
        std::cout << "Bulk_quote(Bulk_quote &&b) noexcept" <<std::endl;
    }

    double net_price(std::size_t) const override;

    void debug() const override {
        std::cout << "min_qty: " << min_qty << "discount: " << discount;
    }

    ~Bulk_quote() override {
        std::cout << "~Bulk_quote()" << std::endl;
    }

protected: // 考虑 5.7 要用到
    std::size_t min_qty = 0;
    double discount = 0.0;
};

Bulk_quote::Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) :
        Quote(book, p), min_qty(qty), discount(disc) {
    std::cout << "Bulk_quote(const std::string &, double, std::size_t, double)" << std::endl;
}

double Bulk_quote::net_price(std::size_t cnt) const {
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

#endif //C__PRIMER_BULK_QUOTE_5_H
