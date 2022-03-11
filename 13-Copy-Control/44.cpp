//
// Created by CottonCandyZ on 3/8/22.
//

#include "String_1.h"

int main() {
    String s1("hello");
    String s2 = s1;
    String s3(s2);
    std::cout << s1.c_str()
              << s2.c_str()
              << s3.c_str()
              << std::endl;
    return 0;
}