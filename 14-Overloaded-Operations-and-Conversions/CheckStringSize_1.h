//
// Created by CottonCandyZ on 3/12/22.
//

#ifndef C__PRIMER_CHECKSTRINGSIZE_1_H
#define C__PRIMER_CHECKSTRINGSIZE_1_H

#include <string>

class CheckStringSize {
public:
    explicit CheckStringSize(size_t n) : threshold(n) {}

    bool operator()(const std::string &s) const {
        return s.size() == threshold;
    }

private:
    size_t threshold;
};

#endif //C__PRIMER_CHECKSTRINGSIZE_1_H
