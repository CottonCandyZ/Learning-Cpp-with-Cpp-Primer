//
// Created by CottonCandyZ on 2/20/22.
//

#include <iostream>
#include "51.h"

int main() {
    Date date1("January 1, 1900");
    Date date2("1/1/1900");
    Date date3("Jan 1 1900");
    date1.print(std::cout) << std::endl;
    date2.print(std::cout) << std::endl;
    date3.print(std::cout) << std::endl;
    return 0;
}