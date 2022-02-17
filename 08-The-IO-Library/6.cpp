//
// Created by CottonCandyZ on 2/16/22.
//

#include <iostream>
#include <fstream>
#include "../07-Classes/Sales_data_2.h"

using std::cin, std::cout, std::endl, std::fstream;

int main(int, char *argv[]) {
    fstream input(argv[1]);
    Sales_data total;
    if (read(input, total)) {
        Sales_data trans;
        while (read(input, trans)) {
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