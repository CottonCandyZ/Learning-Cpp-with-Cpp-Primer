//
// Created by CottonCandyZ on 3/13/22.
//

#include "Sales_data_11.h"

int main() {
    Sales_data salesData("978-7-121-15535-2", 2, 128);
    std::cout << static_cast<std::string >(salesData) << " " << static_cast<double>(salesData) << std::endl;
    return 0;
}