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

    std::string rep() const { return q->rep(); }

    Query(const Query &rhs) : q(rhs.q), ref_count(rhs.ref_count) {
        ++*ref_count;
    }

    Query(Query &&rhs) noexcept : q(rhs.q), ref_count(rhs.ref_count) {
        rhs.q = nullptr;
        rhs.ref_count = nullptr;
    }

    Query &operator=(const Query &rhs) {
        if (this != &rhs) {
            if (--*ref_count == 0) { // 处理左侧的值
                delete q;
                delete ref_count;
            }
            q = rhs.q;
            ref_count = rhs.ref_count;
            ++*ref_count;
        }
        return *this;
    }

    Query &operator=(Query &&rhs)  noexcept {
        if (this != &rhs) {
            if (--*ref_count == 0) {
                delete q;
                delete ref_count;
            }
            q = rhs.q;
            ref_count = rhs.ref_count;
            rhs.q  = nullptr;
            rhs.ref_count = nullptr;
        }
        return *this;
    }

    ~Query() {
        if (--*ref_count == 0) {
            delete q;
            delete ref_count;
        }
    }

private:
    Query(Query_base *query) : q(query), ref_count(new size_t(1)) {}

    Query_base *q;
    size_t *ref_count;
};

std::ostream &operator<<(std::ostream &os, const Query &query) { return os << query.rep(); }

#endif //C__PRIMER_QUERY_H
