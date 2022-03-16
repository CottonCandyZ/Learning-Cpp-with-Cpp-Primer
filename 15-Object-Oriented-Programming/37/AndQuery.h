//
// Created by CottonCandyZ on 3/15/22.
//

#ifndef C__PRIMER_ANDQUERY_H
#define C__PRIMER_ANDQUERY_H

#include "BinaryQuery.h"

class AndQuery : public BinaryQuery {
    friend Query operator&(const Query &, const Query &);

//    AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&") {}

    AndQuery(std::shared_ptr<Query_base> left, std::shared_ptr<Query_base> right) : BinaryQuery(left, right, "&") {}

    QueryResult eval(const TextQuery &) const override;
};

inline Query operator&(const Query &lhs, const Query &rhs) {
//    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
    return std::shared_ptr<Query_base>(new AndQuery(lhs.q, rhs.q));
}

#endif //C__PRIMER_ANDQUERY_H
