//
// Created by CottonCandyZ on 3/12/22.
//

#ifndef C__PRIMER_CHECKSTRINGSIZE_2_H
#define C__PRIMER_CHECKSTRINGSIZE_2_H

#include <string>

class CheckStringSize {
public:
    CheckStringSize(size_t b, size_t e) : begin(b), end(e) {}
    bool operator()(const std::string &s) {
        return s.size() >= begin && s.size() <= end;
    }
private:
    size_t begin, end;
};

#endif //C__PRIMER_CHECKSTRINGSIZE_2_H
