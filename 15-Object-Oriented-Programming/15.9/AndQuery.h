//
// Created by CottonCandyZ on 3/15/22.
//

#ifndef C__PRIMER_ANDQUERY_H
#define C__PRIMER_ANDQUERY_H

#include "BinaryQuery.h"

class AndQuery : public BinaryQuery {
    friend Query operator&(const Query &, const Query &);

    AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&") {}

    QueryResult eval(const TextQuery &) const override;
};

inline Query operator&(const Query &lhs, const Query &rhs) {
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

QueryResult AndQuery::eval(const TextQuery &text) const {
    auto left = lhs.eval(text), right = rhs.eval(text);
    auto ret_lines = std::make_shared<std::set<line_no>>();
    // 求交集
    std::set_intersection(left.begin(), left.end(), right.begin(), right.end(),
                          std::inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}

#endif //C__PRIMER_ANDQUERY_H
