//
// Created by CottonCandyZ on 3/15/22.
//

#ifndef C__PRIMER_NOTQUERY_H
#define C__PRIMER_NOTQUERY_H

#include "Query.h"

class Query;

class NotQuery : public Query_base {
    friend Query operator~(const Query &);

//    NotQuery(const Query &q) : query(q) {}
    NotQuery(std::shared_ptr<Query_base> q) : query(q) {}

    std::string rep() const override { return "~(" + query->rep() + ")"; }

    QueryResult eval(const TextQuery &) const override;

//    Query query;
    std::shared_ptr<Query_base> query;
};


inline Query operator~(const Query &operand) {
    return std::shared_ptr<Query_base>(new NotQuery(operand.q));
}

#endif //C__PRIMER_NOTQUERY_H
