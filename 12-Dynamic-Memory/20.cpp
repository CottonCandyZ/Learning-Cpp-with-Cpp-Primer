//
// Created by CottonCandyZ on 3/2/22.
//

#include <iostream>
#include <fstream>
#include "StrBlobPtr_1.h"


int main() {
    std::string buf;
    StrBlob strBlob;
    std::ifstream file("../12-Dynamic-Memory/20_input");

    while (std::getline(file, buf)) {
        strBlob.push_back(buf);
    }
    for(auto beg = strBlob.begin(), end = strBlob.end(); beg != end; beg.incr()) {
        std::cout << beg.deref() << std::endl;
    }


    return 0;
}