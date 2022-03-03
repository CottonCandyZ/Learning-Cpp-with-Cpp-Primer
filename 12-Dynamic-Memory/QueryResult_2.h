//
// Created by CottonCandyZ on 3/3/22.
//

#ifndef C__PRIMER_QUERYRESULT_2_H
#define C__PRIMER_QUERYRESULT_2_H

#include "TextQuery_2.h"

class QueryResult {
    friend std::ostream &print(std::ostream &, const QueryResult &);

public:
    QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>> p,
                std::shared_ptr<std::vector<std::string>> f) : sought(s), lines(p), file(f) {
    }

private:
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};

QueryResult TextQuery::query(const std::string &sought) const {
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>); // 没找到

    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

std::ostream &print(std::ostream &os, const QueryResult &qr) {
    os << qr.sought << " occurs " << qr.lines->size()
       << (qr.lines->size() > 1 ? " times" : " time") << std::endl;
    for (const auto &item: *qr.lines) {
        os << "\t(line " << item + 1 << ") "
           << *(qr.file->begin() + item) << std::endl;
    }
    return os;
}

#endif //C__PRIMER_QUERYRESULT_2_H