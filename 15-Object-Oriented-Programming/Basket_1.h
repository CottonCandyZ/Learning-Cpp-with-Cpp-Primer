//
// Created by CottonCandyZ on 3/15/22.
//

#ifndef C__PRIMER_BASKET_1_H
#define C__PRIMER_BASKET_1_H

#include <memory>
#include "Bulk_quote_7.h"
#include <set>

// 购物篮
class Basket {
public:
    // 使用合成的构造函数和拷贝控制成员
    void add_item(const std::shared_ptr<Quote> &sale) { items.insert(sale); } // 添加

    void add_item(const Quote & sale) {
        items.insert(std::shared_ptr<Quote>(sale.clone()));
    }

    void add_item(Quote && sale) {
        items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
    }

    // 打印每本书的总价和购物篮中所有书的总价
    double total_receipt(std::ostream &) const;

private:
    // set 需要一个比较函数
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) {
        return lhs->isbn() < rhs->isbn();
    }

    std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare}; // 使用 multiset 同一本书的多条交易就能保存在在一起
};

double Basket::total_receipt(std::ostream &os) const {
    double sum = 0.0;

    // iter 指向相同的第一个
    for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) {
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Sale: " << sum << std::endl;
    return sum;
}



#endif //C__PRIMER_BASKET_1_H
