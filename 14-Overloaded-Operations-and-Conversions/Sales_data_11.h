//
// Created by CottonCandyZ on 3/13/22.
//

#ifndef C__PRIMER_SALES_DATA_11_H
#define C__PRIMER_SALES_DATA_11_H

#include <iostream>
#include <string>

// 需要补充他们的定义
struct Sales_data;

std::istream &read(std::istream &is, Sales_data &item);

struct Sales_data {
    friend std::istream &operator>>(std::istream &is, Sales_data &item);

    friend std::ostream & operator<<(std::ostream &,const Sales_data &);

    friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);

public:
    Sales_data(const std::string &s, unsigned n, double p) :
            bookNo(s), units_sold(n), revenue(p * n) {
        std::cout << "Sales_data(const std::string &s, unsigned n, double p) start" << std::endl;
    }

    Sales_data() : Sales_data("", 0, 0) {
        std::cout << "Sales_data() start" << std::endl;
    }

    Sales_data(const std::string &s) : Sales_data(s, 0, 0) {
        std::cout << "Sales_data(const std::string &s) start" << std::endl;
    }

    Sales_data(std::istream &is) : Sales_data() {
        std::cout << "Sales_data(std::istream &is) start" << std::endl;
        read(is, *this);
    }

    Sales_data& operator+=(const Sales_data&);

    Sales_data& operator=(const std::string &);

    std::string isbn() const { return bookNo; }

    Sales_data &combine(const Sales_data &);

    explicit operator std::string () const {
        return bookNo;
    }

    explicit operator double() const {
        return avg_price();
    }

private:
    inline double avg_price() const {
        return units_sold ? revenue / units_sold : 0;
    }

    std::string bookNo;
    unsigned units_sold{0};
    double revenue{0};

};

Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

std::istream &operator>>(std::istream &is, Sales_data &item) {
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    if (is) // 处理输入错误的情况
        item.revenue = price * item.units_sold;
    else
        item = Sales_data();
    return is;
}

std::ostream &operator<<(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue;
    return os;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
    Sales_data old_data = *this;
    *this = old_data + rhs;
    return *this;
}

Sales_data &Sales_data::operator=(const std::string &isbn) {
    *this = Sales_data(isbn);
    return *this;
}

#endif //C__PRIMER_SALES_DATA_11_H
