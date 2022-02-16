//
// Created by CottonCandyZ on 2/14/22.
//

#include <iostream>
#include "Screen_2_e.h"

using std::cout, std::endl;

void test() {
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << endl;
    myScreen.display(cout);
    cout << endl;
}


int main() {
    test();
    return 0;
}