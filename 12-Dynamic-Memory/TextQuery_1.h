//
// Created by CottonCandyZ on 3/3/22.
//

#ifndef C__PRIMER_TEXTQUERY_1_H
#define C__PRIMER_TEXTQUERY_1_H

/**
 * 未看 12.3.2 时完成，不具备参考意义
 */

#include <fstream>
#include <memory>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include "QueryResult_1.h"

class TextQuery {
public:
    explicit TextQuery(std::ifstream &input_file) {
        read(input_file);
    }

    QueryResult query(std::string&);

private:
    std::shared_ptr<std::vector<std::string>> input_words = std::make_shared<std::vector<std::string>>();
    std::shared_ptr<std::map<std::string, std::set<int>>> line_map =
            std::make_shared<std::map<std::string, std::set<int>>>();
    void read(std::ifstream &);
};

void TextQuery::read(std::ifstream &input_file) {
    std::string buf;
    int current_line_number = 1; // 可以直接用现成的 input_words.size() - 1
    while (std::getline(input_file, buf)) {
        input_words->push_back(buf);
        std::istringstream line(buf); // 当前行字符串
        std::string word; // 单个单词
        while (line >> word) {
            auto p = line_map->find(word); // 先看看在不在
            if (p == line_map->end()) { // 不在 set 要新建
                line_map->emplace(word, std::set<int>{current_line_number});
            } else { // 在的话直接添加行号
                p->second.emplace(current_line_number);
            }
        }
        ++current_line_number;
    }
}

QueryResult TextQuery::query(std::string &s) {
    return QueryResult(input_words, line_map, s); // 可以考虑只传递 set, 而不是整个 map
}


#endif //C__PRIMER_TEXTQUERY_1_H
