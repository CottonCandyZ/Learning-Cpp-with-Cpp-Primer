//
// Created by CottonCandyZ on 3/11/22.
//

#ifndef C__PRIMER_STRVEC_6_H
#define C__PRIMER_STRVEC_6_H

#include <memory>
#include <string>
#include <algorithm>

class StrVec {
    friend bool operator==(const StrVec &, const StrVec &);

    friend bool operator!=(const StrVec &, const StrVec &);

    friend bool operator<(const StrVec &, const StrVec &);

    friend bool operator>(const StrVec &, const StrVec &);

    friend bool operator<=(const StrVec &, const StrVec &);

    friend bool operator>=(const StrVec &, const StrVec &);

public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}

    StrVec(std::initializer_list<std::string>);

    StrVec(const StrVec &);

    StrVec(StrVec &&);

    StrVec &operator=(const StrVec &);

    StrVec &operator=(StrVec &&);

    ~StrVec();

    void push_back(const std::string &);

    size_t size() const { return first_free - elements; }

    size_t capacity() const { return cap - elements; }

    std::string *begin() const { return elements; }

    std::string *end() const { return first_free; }

    void reserve(size_t n);

    void resize(size_t n);

    void resize(size_t n, const std::string &);

private:
    using allo = std::allocator_traits<std::allocator<std::string>>;

    std::allocator<std::string> alloc;

    void chk_n_alloc() { if (size() == capacity()) reallocate(); }

    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);

    void free();

    void reallocate();

    void reallocate_n(size_t n);

    void alloc_range(const std::string *, const std::string *);

    std::string *elements; // 首元素
    std::string *first_free;
    std::string *cap; // 尾
};

void StrVec::push_back(const std::string &s) {
    chk_n_alloc();
    // 分配元素，这里不使用书上的方式，因为书上的方式在 C++20 已经 removed。
    allo::construct(alloc, first_free++, s);
}

std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
    auto data = allo::allocate(alloc, e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    if (elements) {
        std::for_each(first_free, elements,
                      [this](std::string &p) { allo::destroy(alloc, &p); });
        allo::deallocate(alloc, elements, cap - elements);
    }
}


void StrVec::alloc_range(const std::string *b, const std::string *e) {
    auto newdata = alloc_n_copy(b, e);
    elements = newdata.first;
    first_free = cap = newdata.second;
}

// 初始化的时候使用传入参数的长度
StrVec::StrVec(const StrVec &s) {
    alloc_range(s.begin(), s.end());
}

StrVec::~StrVec() { free(); }

StrVec &StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free(); // 清空左侧的值
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate_n(size_t n) {
    auto newdata = allo::allocate(alloc, n); // 分配空间
    auto dest = newdata; // 新的
    auto elem = elements; // 旧的
    for (size_t i = 0; i != size(); ++i) {
        allo::construct(alloc, dest++, std::move(*elem++)); // 移动构造
    }
    free(); // 释放原有的内存空间
    elements = newdata; // 给上新的
    first_free = dest;
    cap = elements + n;
}

void StrVec::reallocate() {
    reallocate_n(size() ? 2 * size() : 1);
}


void StrVec::reserve(size_t n) {
    if (n <= capacity()) return;
    reallocate_n(n);
}

void StrVec::resize(size_t n) {
    resize(n, std::string());
}

void StrVec::resize(size_t n, const std::string &s) {
    if (n > size()) {
        if (n > capacity()) reserve(n * 2); // 使用两倍容量
        for (size_t i = size(); i != n; ++i)
            allo::construct(alloc, first_free++, s); // 初始化填满
    } else if (n < size()) {
        while (first_free != elements + n)
            allo::destroy(alloc, --first_free);
    }
}

StrVec::StrVec(std::initializer_list<std::string> il) {
    alloc_range(il.begin(), il.end());
}

StrVec::StrVec(StrVec &&s) : elements(s.elements), first_free(s.first_free), cap(s.cap) {
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec &StrVec::operator=(StrVec &&rhs) {
    if (&rhs != this) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

bool operator==(const StrVec &lhs, const StrVec &rhs) {
    return (lhs.size() == rhs.size() &&
            std::equal(lhs.begin(), lhs.end(), rhs.begin())); // 有所参考
}

bool operator!=(const StrVec &lhs, const StrVec &rhs) {
    return !(lhs == rhs);
}

bool operator<(const StrVec &lhs, const StrVec &rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

bool operator>(const StrVec &lhs, const StrVec &rhs) {
    return rhs < lhs;
}

bool operator<=(const StrVec &lhs, const StrVec &rhs) {
    return !(lhs > rhs);
}

bool operator>=(const StrVec &lhs, const StrVec &rhs) {
    return !(lhs < rhs);
}


#endif //C__PRIMER_STRVEC_6_H
