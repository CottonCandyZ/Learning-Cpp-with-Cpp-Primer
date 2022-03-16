//
// Created by CottonCandyZ on 3/15/22.
//

#ifndef C__PRIMER_BINARYQUERY_H
#define C__PRIMER_BINARYQUERY_H

#include "Query.h"

class BinaryQuery : public Query_base {
protected:
//    BinaryQuery(const Query &l, const Query &r, std::string s) : lhs(l), rhs(r), opSym(s) {}
    BinaryQuery(std::shared_ptr<Query_base> &l, std::shared_ptr<Query_base> &r, std::string s) : lhs(l), rhs(r),
                                                                                                 opSym(s) {}

//    std::string rep() const override { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }
    std::string rep() const override { return "(" + lhs->rep() + " " + opSym + " " + rhs->rep() + ")"; }

//    Query lhs, rhs;
    std::string opSym; // 运算符的名字

    std::shared_ptr<Query_base> lhs, rhs;
};

#endif //C__PRIMER_BINARYQUERY_H
