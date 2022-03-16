//
// Created by CottonCandyZ on 3/15/22.
//

#ifndef C__PRIMER_QUOTE_3_H
#define C__PRIMER_QUOTE_3_H

#include <string>
#include <iostream>

class Quote {
public:
    Quote() {
        std::cout << "Quote()" << std::endl;
    }

    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {
        std::cout << "Quote(const std::string &book, double sales_price)" << std::endl;
    }

    Quote &operator=(const Quote &q) {
        bookNo = q.bookNo;
        price = q.price;
        std::cout << "Quote &operator=(const Quote &q)" << std::endl;
        return *this;
    }

    Quote &operator=(Quote &&q) noexcept {
        bookNo = std::move(q.bookNo);
        price = std::move(q.price);
        std::cout << "Quote &operator=(Quote &&q) noexcept" << std::endl;
        return *this;
    }

    Quote(const Quote &q) : bookNo(q.bookNo), price(q.price) {
        std::cout << "Quote(const Quote &q)" << std::endl;
    }

    Quote(Quote &&q) noexcept: bookNo(std::move(q.bookNo)), price(std::move(q.price)) {
        std::cout << "Quote(Quote &&q) noexcept" << std::endl;
    }

    std::string isbn() const { return bookNo; }

    virtual double net_price(std::size_t n) const { return n * price; }

    virtual void debug() const {
        std::cout << "bookNo: " << bookNo << ", price: " << price;
    }

    virtual ~Quote() {
        std::cout << "~Quote()" << std::endl;
    }

private:
    std::string bookNo;
protected:
    double price = 0.0;
};

double print_total(std::ostream &os, Quote const &item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

#endif //C__PRIMER_QUOTE_3_H
