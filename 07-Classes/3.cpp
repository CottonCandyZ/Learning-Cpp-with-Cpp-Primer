//
// Created by CottonCandyZ on 2/11/22.
//

#include <iostream>
#include "Sales_data_1.h"

using std::cin, std::cout, std::endl;

void print(const Sales_data &data) {
    cout << data.bookNo << " "
         << data.units_sold << " "
         << data.revenue << endl;
}

int main() {
    Sales_data total;
    double price;
    if (cin >> total.bookNo >> total.units_sold >> price) {
        total.revenue = price * total.units_sold;
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> price) {
            trans.revenue = price * trans.units_sold;
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(total);
                total = trans;
            }
        }
        print(total);
    } else {
        std::cerr << "No data?!" << endl;
    }

    return 0;
}