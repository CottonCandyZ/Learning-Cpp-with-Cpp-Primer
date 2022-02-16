//
// Created by CottonCandyZ on 2/11/22.
//

#include "../02-Variables-and-Basic-Types/Sales_data.h"
#include <iostream>

void print (Sales_data data) {
    std::cout << data.bookNo << " "
              << data.units_sold << " "
              << data.revenue << std::endl;
}

int main() {
    Sales_data total;
    double price;
    if (std::cin >> total.bookNo >> total.units_sold >> price) {
        total.revenue = price * total.units_sold;
        Sales_data trans;
        while (std::cin >> trans.bookNo >> trans.units_sold >> price) {
            trans.revenue = price * total.units_sold;
            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            } else {
                print(total);
                total.bookNo = trans.bookNo;
                total.units_sold = trans.units_sold;
                total.revenue = trans.revenue;
            }
        }
        print(total);
    } else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}