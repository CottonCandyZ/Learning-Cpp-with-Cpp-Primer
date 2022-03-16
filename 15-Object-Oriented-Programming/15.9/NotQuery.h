//
// Created by CottonCandyZ on 3/15/22.
//

#ifndef C__PRIMER_NOTQUERY_H
#define C__PRIMER_NOTQUERY_H

#include "Query.h"

class Query;

class NotQuery : public Query_base {
    friend Query operator~(const Query &);

    NotQuery(const Query &q) : query(q) {}

    std::string rep() const override { return "~(" + query.rep() + ")"; }

    QueryResult eval(const TextQuery &) const override;

    Query query;
};

inline Query operator~(const Query &operand) {
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

QueryResult NotQuery::eval(const TextQuery &text) const {
    auto result = query.eval(text);
    auto ret_lines = std::make_shared<std::set<line_no>>();
    auto begin = result.begin(), end = result.end();
    auto sz = result.get_file()->size();
    for (size_t n = 0; n != sz; ++n) {
        if (begin == end || *begin != n) { // 不在 result 中
            ret_lines->insert(n);
        } else if (begin != end) // 在 result 中
            ++begin; // 下移迭代器
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}

#endif //C__PRIMER_NOTQUERY_H
