//
// Created by CottonCandyZ on 3/12/22.
//

#ifndef C__PRIMER_STRBLOBPTR_6_H
#define C__PRIMER_STRBLOBPTR_6_H

#include "StrBlob_5.h"

class StrBlobPtr {
    friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);

    friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);

    friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);

    friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);

    friend bool operator<=(const StrBlobPtr &, const StrBlobPtr &);

    friend bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

public:
    StrBlobPtr() : curr(0) {}

    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

    std::string &deref() const;

    StrBlobPtr &incr();

    bool operator!=(const StrBlobPtr &p) { return p.curr != curr; } // 增加一个函数，方便 20 题的自增

    std::string &operator=(size_t n);

    const std::string &operator=(size_t n) const;

    StrBlobPtr &operator++();

    StrBlobPtr &operator--();

    StrBlobPtr operator++(int);

    StrBlobPtr operator--(int);

    StrBlobPtr &operator+=(size_t);

    StrBlobPtr &operator-=(size_t);

    StrBlobPtr operator+(size_t) const;

    StrBlobPtr operator-(size_t) const;


private:
    using vec_string = std::vector<std::string>;

    std::shared_ptr<vec_string> check(std::size_t, const std::string &) const;

    std::weak_ptr<vec_string> wptr;
    std::size_t curr;
};

/**
 * 用来检查当前指针指向的内存空间是否还在，或是访问位置 i 是否超过 vec 的长度
 * @param i 访问位置
 * @param msg 超过长度时的错误信息
 * @return 返回一个 shared_ptr
 */
std::shared_ptr<StrBlobPtr::vec_string> StrBlobPtr::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret;
}

/**
 * 得到当前 curr 指向位置的引用，在越界时跑出一个异常
 * @return 当前 curr 指向位置的引用
 */
std::string &StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

/**
 * 递增当前 curr 指向的位置
 * @return 返回该类自身的引用
 */
StrBlobPtr &StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return lhs.curr < rhs.curr;
}

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return rhs < lhs;
}

bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(rhs < lhs);
}

bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(lhs < rhs);
}

std::string &StrBlobPtr::operator=(size_t n) {
    auto p = check(n, "dereference out of range.");
    return (*p)[n];
}

const std::string &StrBlobPtr::operator=(size_t n) const {
    auto p = check(n, "dereference out of range.");
    return (*p)[n];
}

StrBlobPtr &StrBlobPtr::operator++() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr &StrBlobPtr::operator--() {
    --curr;
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int) {
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}

StrBlobPtr StrBlobPtr::operator--(int) {
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}

StrBlobPtr &StrBlobPtr::operator+=(size_t n) {
    curr += n;
    check(curr, "increment past end of StrBlobPtr");
    return *this;
}

StrBlobPtr &StrBlobPtr::operator-=(size_t n) {
    curr -= n;
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}

StrBlobPtr StrBlobPtr::operator+(size_t n) const {
    StrBlobPtr ret = *this;
    ret += n;
    return ret;
}

StrBlobPtr StrBlobPtr::operator-(size_t n) const {
    StrBlobPtr ret = *this;
    ret += n;
    return ret;
}


#endif //C__PRIMER_STRBLOBPTR_6_H
