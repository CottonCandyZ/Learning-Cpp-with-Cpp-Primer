//
// Created by CottonCandyZ on 2/12/22.
//

#include <iostream>
#include "Sales_data_3.h"

int main() {
    Sales_data salesData_1("0-201-70353-X");
    Sales_data salesData_2("0-201-70353-X", 4, 24.99);
    Sales_data salesData_3;
    Sales_data salesData_4(std::cin);
    print(std::cout, salesData_1) << std::endl;
    print(std::cout, salesData_2) << std::endl;
    print(std::cout, salesData_3) << std::endl;
    print(std::cout, salesData_4) << std::endl;
    return 0;
}