//
// Created by CottonCandyZ on 3/17/22.
//

#ifndef C__PRIMER_BLOBPTR_1_H
#define C__PRIMER_BLOBPTR_1_H

#include <string>

#include "Blob_1.h"


template<typename T>
class BlobPtr {
    friend bool operator==(const BlobPtr &, const BlobPtr &);

    friend bool operator!=(const BlobPtr &, const BlobPtr &);

    friend bool operator<(const BlobPtr &, const BlobPtr &);

    friend bool operator>(const BlobPtr &, const BlobPtr &);

    friend bool operator<=(const BlobPtr &, const BlobPtr &);

    friend bool operator>=(const BlobPtr &, const BlobPtr &);

public:
    BlobPtr() : curr(0) {}

    BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

    T &deref() const;

    BlobPtr &incr();

    bool operator!=(const BlobPtr &p) { return p.curr != curr; } // 增加一个函数，方便 20 题的自增

    T &operator=(size_t n);

    const T &operator=(size_t n) const;

    BlobPtr &operator++();

    BlobPtr &operator--();

    BlobPtr operator++(int);

    BlobPtr operator--(int);

    BlobPtr &operator+=(size_t);

    BlobPtr &operator-=(size_t);

    BlobPtr operator+(size_t) const;

    BlobPtr operator-(size_t) const;

    T &operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    };

    T *operator->() const {
        return &this->operator*();
    };

private:
    using vec_T = std::vector<T>;

    std::shared_ptr<vec_T> check(std::size_t, const std::string &) const;

    std::weak_ptr<vec_T> wptr;
    std::size_t curr;
};

/**
 * 用来检查当前指针指向的内存空间是否还在，或是访问位置 i 是否超过 vec 的长度
 * @param i 访问位置
 * @param msg 超过长度时的错误信息
 * @return 返回一个 shared_ptr
 */
template<typename T>
std::shared_ptr<typename BlobPtr<T>::vec_T> BlobPtr<T>::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound BlobPtr");
    if (i >= ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret;
}

/**
 * 得到当前 curr 指向位置的引用，在越界时跑出一个异常
 * @return 当前 curr 指向位置的引用
 */
template<typename T>
T &BlobPtr<T>::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

/**
 * 递增当前 curr 指向的位置
 * @return 返回该类自身的引用
 */
template<typename T>
BlobPtr<T> &BlobPtr<T>::incr() {
    check(curr, "increment past end of BlobPtr");
    ++curr;
    return *this;
}

template<typename T>
BlobPtr<T> Blob<T>::begin() {
    return BlobPtr(*this);
}

template<typename T>
BlobPtr<T> Blob<T>::end() {
    auto ret = BlobPtr(*this, data->size());
    return ret;
}

template<typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return lhs.curr == rhs.curr;
}

template<typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return !(lhs == rhs);
}

template<typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return lhs.curr < rhs.curr;
}

template<typename T>
bool operator>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return rhs < lhs;
}

template<typename T>
bool operator<=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return !(rhs < lhs);
}

template<typename T>
bool operator>=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return !(lhs < rhs);
}

template<typename T>
T &BlobPtr<T>::operator=(size_t n) {
    auto p = check(n, "dereference out of range.");
    return (*p)[n];
}

template<typename T>
const T &BlobPtr<T>::operator=(size_t n) const {
    auto p = check(n, "dereference out of range.");
    return (*p)[n];
}

template<typename T>
BlobPtr<T> &BlobPtr<T>::operator++() {
    check(curr, "increment past end of BlobPtr");
    ++curr;
    return *this;
}

template<typename T>
BlobPtr<T> &BlobPtr<T>::operator--() {
    --curr;
    check(curr, "decrement past begin of BlobPtr");
    return *this;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator--(int) {
    BlobPtr ret = *this;
    --*this;
    return ret;
}

template<typename T>
BlobPtr<T> &BlobPtr<T>::operator+=(size_t n) {
    curr += n;
    check(curr, "increment past end of BlobPtr");
    return *this;
}

template<typename T>
BlobPtr<T> &BlobPtr<T>::operator-=(size_t n) {
    curr -= n;
    check(curr, "decrement past begin of BlobPtr");
    return *this;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator+(size_t n) const {
    BlobPtr ret = *this;
    ret += n;
    return ret;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator-(size_t n) const {
    BlobPtr ret = *this;
    ret += n;
    return ret;
}

#endif //C__PRIMER_BLOBPTR_1_H
