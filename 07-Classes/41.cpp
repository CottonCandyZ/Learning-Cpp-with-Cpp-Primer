//
// Created by CottonCandyZ on 2/15/22.
//

#include "Sales_data_7.h"

void test() {
    std::cout << "salesData_1:" << std::endl;
    Sales_data salesData_1;
    std::cout << "------------------------------" << std::endl;
    std::cout << "salesData_2(\"T\")" << std::endl;
    Sales_data salesData_2("T");
    std::cout << "------------------------------" << std::endl;
    std::cout << "salesData_3(std::cin):" << std::endl;
    Sales_data salesData_3(std::cin);
}


int main() {
    test();
    return 0;
}