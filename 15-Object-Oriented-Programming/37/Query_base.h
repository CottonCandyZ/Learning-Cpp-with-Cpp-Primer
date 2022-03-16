//
// Created by CottonCandyZ on 3/15/22.
//

#ifndef C__PRIMER_QUERY_BASE_H
#define C__PRIMER_QUERY_BASE_H

#include "../../12-Dynamic-Memory/QueryResult_4.h"

class Query_base {
    friend class Query;
    friend class BinaryQuery;
    friend class NotQuery;

protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;

private:
    // 返回当前 Query 匹配的 QueryResult
    virtual QueryResult eval(const TextQuery&) const = 0;
    // rep 是表示查询的一个 string
    virtual std::string rep() const = 0;
};

#endif //C__PRIMER_QUERY_BASE_H
