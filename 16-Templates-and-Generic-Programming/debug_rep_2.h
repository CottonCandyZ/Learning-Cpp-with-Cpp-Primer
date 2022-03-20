//
// Created by CottonCandyZ on 3/19/22.
//

#ifndef C__PRIMER_DEBUG_REP_2_H
#define C__PRIMER_DEBUG_REP_2_H
#include <string>
#include <sstream>
template <typename T> std::string debug_rep(const T &t) {
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename T> std::string debug_rep(T *p) {
    std::ostringstream ret;
    ret << "pointer: " << p;
    if (p) {
        ret << " " << debug_rep(*p);
    } else {
        ret << " null pointer";
    }
    return ret.str();
}

template <>
std::string debug_rep(const char *p) {
    std::string s(p);
    return '"' + s + '"';
}

template <>
std::string debug_rep(char *p) {
    std::string s(p);
    return '"' + s + '"';
}




#endif //C__PRIMER_DEBUG_REP_2_H
