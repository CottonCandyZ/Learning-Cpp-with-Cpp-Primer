//
// Created by CottonCandyZ on 2/12/22.
//

#include <iostream>
#include "Sales_data_4.h"

using std::cin, std::cout, std::endl;

int main() {
    Sales_data total(cin);
    if (std::cin) {
        Sales_data trans(cin);
        while (std::cin) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(cout, total) << endl;
                total = trans;
            }
            read(cin, trans);
        }
        print(cout, total) << endl;
    } else {
        std::cerr << "No data?!" << endl;
    }

    return 0;
}