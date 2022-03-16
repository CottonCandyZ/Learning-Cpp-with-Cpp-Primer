//
// Created by CottonCandyZ on 3/16/22.
//

#include "36/OrQuery.h"
#include "36/AndQuery.h"
#include "36/WordQuery.h"

int main() {
    Query q = Query("fiery") & Query("bird") | Query("wind");
    std::cout << q;
    return 0;
}