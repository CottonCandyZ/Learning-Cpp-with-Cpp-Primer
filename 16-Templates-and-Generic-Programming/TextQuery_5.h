//
// Created by CottonCandyZ on 3/17/22.
//

#ifndef C__PRIMER_TEXTQUERY_5_H
#define C__PRIMER_TEXTQUERY_5_H

#include <vector>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <memory>

#include "DebugDelete_1.h"


class QueryResult;
class TextQuery {
public:
    using line_no = std::vector<std::string >::size_type;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;

private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};


TextQuery::TextQuery(std::ifstream& is) : file(new std::vector<std::string>, DebugDelete()){
    std::string text;
    while (std::getline(is, text)) {
        file->push_back(text);
        int n = file->size() - 1;
        std::istringstream line(text);
        std::string word;
        while (line >> word) {
            auto &lines = wm[word];
            if (!lines) {
                lines.reset(new std::set<line_no>, DebugDelete());
            }
            lines->insert(n);
        }
    }
}


#endif //C__PRIMER_TEXTQUERY_5_H