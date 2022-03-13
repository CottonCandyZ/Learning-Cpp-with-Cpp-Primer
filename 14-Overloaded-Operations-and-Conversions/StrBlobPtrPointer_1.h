//
// Created by CottonCandyZ on 3/12/22.
//

#ifndef C__PRIMER_STRBLOBPTRPOINTER_1_H
#define C__PRIMER_STRBLOBPTRPOINTER_1_H

#include "StrBlobPtr_7.h"

class StrBlobPtrPointer {
public:
    StrBlobPtrPointer() = default;
    StrBlobPtrPointer(StrBlobPtr* p) : pointer(p) {}
    StrBlobPtr& operator*();
    StrBlobPtr* operator->();
private:
    StrBlobPtr *pointer = nullptr;
};

StrBlobPtr &StrBlobPtrPointer::operator*() {
    return *this->pointer;
}

StrBlobPtr *StrBlobPtrPointer::operator->() {
    return &this->operator*();
}


#endif //C__PRIMER_STRBLOBPTRPOINTER_1_H
