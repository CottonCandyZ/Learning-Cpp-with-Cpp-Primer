//
// Created by CottonCandyZ on 3/15/22.
//

#ifndef C__PRIMER_ORQUERY_H
#define C__PRIMER_ORQUERY_H

#include "BinaryQuery.h"

class OrQuery : public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "|") {}
    QueryResult eval(const TextQuery&) const override;
};

inline Query operator|(const Query &lhs, const Query &rhs) {
    return new OrQuery(lhs, rhs);
}

QueryResult OrQuery::eval(const TextQuery &text) const {
    // 或运算，先得到左右两侧查询的结果
    auto right = rhs.eval(text), left = lhs.eval(text);
    // 将左侧结果，保存在一个 set 中
    auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
    // 随后再插入右侧的，即并上右侧的
    ret_lines->insert(right.begin(), right.end());
    // 最后返回这个并集
    return QueryResult(rep(), ret_lines, left.get_file());
}

#endif //C__PRIMER_ORQUERY_H
