//
// Created by CottonCandyZ on 3/17/22.
//

#ifndef C__PRIMER_DEBUGDELETE_1_H
#define C__PRIMER_DEBUGDELETE_1_H

#include <iostream>

class DebugDelete {
public:
    DebugDelete(std::ostream &s = std::cerr) : os(s) {}

    template<typename T> void operator()(T *p) const {
        os << "deleting unique_ptr" << std::endl;
        delete p;
    }
private:
    std::ostream &os;
};

#endif //C__PRIMER_DEBUGDELETE_1_H
