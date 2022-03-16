//
// Created by CottonCandyZ on 3/15/22.
//

#ifndef C__PRIMER_BINARYQUERY_H
#define C__PRIMER_BINARYQUERY_H

#include "Query.h"

class BinaryQuery : public Query_base {
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s) : lhs(l), rhs(r), opSym(s) {}

    std::string rep() const override { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }

    Query lhs, rhs;
    std::string opSym; // 运算符的名字
};

#endif //C__PRIMER_BINARYQUERY_H
