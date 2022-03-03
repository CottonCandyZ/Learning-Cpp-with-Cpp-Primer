//
// Created by CottonCandyZ on 3/3/22.
//

#ifndef C__PRIMER_QUERYRESULT_1_H
#define C__PRIMER_QUERYRESULT_1_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>

class QueryResult {
public:
    QueryResult(std::shared_ptr<std::vector<std::string>> _input_words,
                std::shared_ptr<std::map<std::string, std::set<int>>> _line_map, std::string& _word) : word(_word) {
        input_words = _input_words;
        line_map = _line_map;
    }
    void print(std::ostream&);

private:
    std::shared_ptr<std::vector<std::string>> input_words;
    std::shared_ptr<std::map<std::string, std::set<int>>> line_map;
    std::string word;
};

void QueryResult::print(std::ostream& os) {
    auto p = line_map->find(word);
    if (p != line_map->end()) { // 不应该在 print 里处理，应该在 query 里处理
        os << word << " occurs " << p->second.size() <<(p->second.size() > 1 ? " times" : " time") << std::endl;
        for (const auto &item:p->second) {
            os << "\t(line " << item << ") " << (*input_words)[item - 1] << std::endl;
        }
    } else {
        os << "no \'" << word << "\' found" << std::endl;
    }
}

std::ostream &print(std::ostream& os, QueryResult queryResult) { // 可以直接声明为 friend
    queryResult.print(os);
    return os;
}


#endif //C__PRIMER_QUERYRESULT_1_H
