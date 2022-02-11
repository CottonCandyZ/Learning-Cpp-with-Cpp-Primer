//
// Created by CottonCandyZ on 1/23/22.
//

#include <iostream>
using std::cout, std::endl;

void reset(int &i) {
    i = 0;
}

int main() {
    int num = 1;
    cout << "before reset: " << num << endl;
    reset(num);
    cout << "after reset: " << num << endl;
    return 0;
}