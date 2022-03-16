//
// Created by CottonCandyZ on 3/15/22.
//

#ifndef C__PRIMER_WORDQUERY_H
#define C__PRIMER_WORDQUERY_H

#include "Query.h"

class WordQuery : public Query_base {
    friend class Query;

    WordQuery(const std::string &s) : query_word(s) {
        std::cout << "WordQuery(const std::string &s)" << std::endl;
    }

    QueryResult eval(const TextQuery &t) const override { return t.query(query_word); }

    std::string rep() const override {
        std::cout << "WordQuery rep()" << std::endl;
        return query_word;
    }

    std::string query_word; // 要查找的单词
};

inline Query::Query(const std::string &s) : q(new WordQuery(s)) {
    std::cout << "Query(const std::string &s)" << std::endl;
}


#endif //C__PRIMER_WORDQUERY_H
