//
// Created by CottonCandyZ on 3/16/22.
//

#include "NotQuery.h"
#include "OrQuery.h"
#include "AndQuery.h"
#include "WordQuery.h"
#include <iostream>

int main() {
    Query q = Query("fiery") & Query("bird") | Query("wind");
    std::ifstream input("../15-Object-Oriented-Programming/41/input");
    auto result = q.eval(TextQuery(input));
    std::cout << "Executing Query for: " << q << std::endl;
    print(std::cout, result);

    return 0;
}