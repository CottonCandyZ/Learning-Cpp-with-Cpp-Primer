//
// Created by CottonCandyZ on 2/17/22.
//

#include <iostream>
#include <fstream>
#include "../07-Classes/Sales_data_2.h"

using std::cin, std::cout, std::endl, std::fstream, std::ofstream;

int main(int, char *argv[]) {
    fstream input(argv[1]);
    ofstream output(argv[2], ofstream::app);
    Sales_data total;
    if (read(input, total)) {
        Sales_data trans;
        while (read(input, trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(output, total) << endl;
                total = trans;
            }
        }
        print(output, total) << endl;
    } else {
        std::cerr << "No data?!" << endl;
    }
    return 0;
}