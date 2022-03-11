//
// Created by CottonCandyZ on 3/5/22.
//

#ifndef C__PRIMER_HASPTR_2_H
#define C__PRIMER_HASPTR_2_H

#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) :
            ps(new std::string(s)), i(0) { }

    HasPtr(const HasPtr &orig) :
            ps(new std::string(*orig.ps)),
            i(orig.i) {}
    HasPtr &operator=(const HasPtr& rhs) {
        /*
         * 若尝试将自身赋予自身，不使用临时变量会导致读取的 ps 指向的内存已经被释放。
         * 例如
         * HasPtr h("t");
         * h = h; // 不使用临时变量，则 ps 指向的内存区域将被释放
         */
        std::string *temp = new std::string(*rhs.ps);
        delete ps;
        ps = temp;
        i = rhs.i;
        return *this;
    }
private:
    std::string *ps;
    int i;
};

#endif //C__PRIMER_HASPTR_2_H
