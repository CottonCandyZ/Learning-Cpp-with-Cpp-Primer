//
// Created by CottonCandyZ on 3/15/22.
//

#ifndef C__PRIMER_QUERY_H
#define C__PRIMER_QUERY_H

#include "Query_base.h"


class Query {
    friend Query operator~(const Query &);

    friend Query operator|(const Query &, const Query &);

    friend Query operator&(const Query &, const Query &);

    friend std::ostream &operator<<(std::ostream &, const Query &);

public:
    Query(const std::string &);

    // 两个 接口函数，调用 Query_base 操作
    QueryResult eval(const TextQuery &t) const { return q->eval(t); }

    std::string rep() const {
        std::cout << "Query rep()" << std::endl;
        return q->rep();
    }

private:
    Query(std::shared_ptr<Query_base> query) : q(query) {
        std::cout << "Query(std::shared_ptr<Query_base> query)" << std::endl;
    }

    std::shared_ptr<Query_base> q;
};

std::ostream &operator<<(std::ostream &os, const Query &query) { return os << query.rep(); }

#endif //C__PRIMER_QUERY_H
