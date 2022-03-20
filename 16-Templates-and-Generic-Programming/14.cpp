//
// Created by CottonCandyZ on 3/17/22.
//

#include <iostream>
#include "Screen_4.h"

int main() {
    Screen<5,5> screen('h');
    screen.display(std::cout);
    return 0;
}