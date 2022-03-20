//
// Created by CottonCandyZ on 3/18/22.
//

#ifndef C__PRIMER_SUM_1_H
#define C__PRIMER_SUM_1_H

template<typename T1, typename T2>
auto sum(const T1 &a, const T2 &b) -> decltype(a + b) {
    return a + b;
}

#endif //C__PRIMER_SUM_1_H
