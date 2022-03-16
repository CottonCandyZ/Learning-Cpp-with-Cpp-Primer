//
// Created by CottonCandyZ on 3/16/22.
//

#include "OrQuery.h"
#include "AndQuery.h"
#include "WordQuery.h"

int main() {
    Query q = Query("fiery") & Query("bird") | Query("wind");
    std::cout << q;
    return 0;
}