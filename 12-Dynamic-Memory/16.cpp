//
// Created by CottonCandyZ on 3/1/22.
//


#include <iostream>
int main() {
    std::unique_ptr<int> uniquePtr;
    std::unique_ptr<int> temp = uniquePtr;
    /*
    error: call to implicitly-deleted copy constructor of 'std::unique_ptr<int>'
    std::unique_ptr<int> temp = uniquePtr;
                         ^      ~~~~~~~~~
     */
    return 0;
}