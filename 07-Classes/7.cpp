//
// Created by CottonCandyZ on 2/11/22.
//

#include <iostream>
#include "Sales_data_2.h"

using std::cin, std::cout, std::endl;

int main() {
    Sales_data total;
    if (read(cin, total)) {
        Sales_data trans;
        while (read(cin, trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    } else {
        std::cerr << "No data?!" << endl;
    }

    return 0;
}