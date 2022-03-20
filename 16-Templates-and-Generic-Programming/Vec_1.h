//
// Created by CottonCandyZ on 3/17/22.
//

#ifndef C__PRIMER_VEC_1_H
#define C__PRIMER_VEC_1_H

#include <memory>
#include <string>
#include <algorithm>

template<typename T>
class Vec;

template<typename T>
bool operator==(const Vec<T> &, const Vec<T> &);

template<typename T>
bool operator!=(const Vec<T> &, const Vec<T> &);

template<typename T>
bool operator<(const Vec<T> &, const Vec<T> &);

template<typename T>
bool operator>(const Vec<T> &, const Vec<T> &);

template<typename T>
bool operator<=(const Vec<T> &, const Vec<T> &);

template<typename T>
bool operator>=(const Vec<T> &, const Vec<T> &);

template<typename T>
class Vec {
    friend bool operator==<T>(const Vec<T> &, const Vec<T> &);

    friend bool operator!=<T>(const Vec<T> &, const Vec<T> &);

    friend bool operator< <T>(const Vec<T> &, const Vec<T> &);

    friend bool operator><T>(const Vec<T> &, const Vec<T> &);

    friend bool operator<=<T>(const Vec<T> &, const Vec<T> &);

    friend bool operator>=<T>(const Vec<T> &, const Vec<T> &);

public:
    Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}

    Vec(std::initializer_list<T>);

    Vec(const Vec &);

    Vec(Vec &&);

    Vec &operator=(const Vec &);

    Vec &operator=(Vec &&);

    Vec &operator=(std::initializer_list<T>);

    ~Vec();

    void push_back(const T &);

    size_t size() const { return first_free - elements; }

    size_t capacity() const { return cap - elements; }

    T *begin() const { return elements; }

    T *end() const { return first_free; }

    void reserve(size_t n);

    void resize(size_t n);

    void resize(size_t n, const T &);

    T &operator[](size_t n);

    const T &operator[](size_t n) const;


private:
    using allo = std::allocator_traits<std::allocator<T>>;

    std::allocator<T> alloc;

    void chk_n_alloc() { if (size() == capacity()) reallocate(); }

    std::pair<T *, T *> alloc_n_copy(const T *, const T *);

    void free();

    void reallocate();

    void reallocate_n(size_t n);

    void alloc_range(const T *, const T *);

    T *elements; // 首元素
    T *first_free;
    T *cap; // 尾
};

template<typename T>
void Vec<T>::push_back(const T &s) {
    chk_n_alloc();
    // 分配元素，这里不使用书上的方式，因为书上的方式在 C++20 已经 removed。
    allo::construct(alloc, first_free++, s);
}

template<typename T>
std::pair<T *, T *> Vec<T>::alloc_n_copy(const T *b, const T *e) {
    auto data = allo::allocate(alloc, e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

template<typename T>
void Vec<T>::free() {
    if (elements) {
        std::for_each(first_free, elements,
                      [this](T &p) { allo::destroy(alloc, &p); });
        allo::deallocate(alloc, elements, cap - elements);
    }
}

template<typename T>
void Vec<T>::alloc_range(const T *b, const T *e) {
    auto newdata = alloc_n_copy(b, e);
    elements = newdata.first;
    first_free = cap = newdata.second;
}

// 初始化的时候使用传入参数的长度
template<typename T>
Vec<T>::Vec(const Vec &s) {
    alloc_range(s.begin(), s.end());
}

template<typename T>
Vec<T>::~Vec() { free(); }

template<typename T>
Vec<T> &Vec<T>::operator=(const Vec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free(); // 清空左侧的值
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

template<typename T>
void Vec<T>::reallocate_n(size_t n) {
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

template<typename T>
void Vec<T>::reallocate() {
    reallocate_n(size() ? 2 * size() : 1);
}

template<typename T>
void Vec<T>::reserve(size_t n) {
    if (n <= capacity()) return;
    reallocate_n(n);
}

template<typename T>
void Vec<T>::resize(size_t n) {
    resize(n, T());
}

template<typename T>
void Vec<T>::resize(size_t n, const T &s) {
    if (n > size()) {
        if (n > capacity()) reserve(n * 2); // 使用两倍容量
        for (size_t i = size(); i != n; ++i)
            allo::construct(alloc, first_free++, s); // 初始化填满
    } else if (n < size()) {
        while (first_free != elements + n)
            allo::destroy(alloc, --first_free);
    }
}

template<typename T>
Vec<T>::Vec(std::initializer_list<T> il) {
    alloc_range(il.begin(), il.end());
}

template<typename T>
Vec<T>::Vec(Vec &&s) : elements(s.elements), first_free(s.first_free), cap(s.cap) {
    s.elements = s.first_free = s.cap = nullptr;
}

template<typename T>
Vec<T> &Vec<T>::operator=(Vec &&rhs) {
    if (&rhs != this) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

template<typename T>
bool operator==(const Vec<T> &lhs, const Vec<T> &rhs) {
    return (lhs.size() == rhs.size() &&
            std::equal(lhs.begin(), lhs.end(), rhs.begin())); // 有所参考
}

template<typename T>
bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs) {
    return !(lhs == rhs);
}

template<typename T>
bool operator<(const Vec<T> &lhs, const Vec<T> &rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template<typename T>
bool operator>(const Vec<T> &lhs, const Vec<T> &rhs) {
    return rhs < lhs;
}

template<typename T>
bool operator<=(const Vec<T> &lhs, const Vec<T> &rhs) {
    return !(lhs > rhs);
}

template<typename T>
bool operator>=(const Vec<T> &lhs, const Vec<T> &rhs) {
    return !(lhs < rhs);
}

template<typename T>
Vec<T> &Vec<T>::operator=(std::initializer_list<T> il) {
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

template<typename T>
T &Vec<T>::operator[](size_t n) {
    return elements[n];
}

template<typename T>
const T &Vec<T>::operator[](size_t n) const {
    return elements[n];
}

#endif //C__PRIMER_VEC_1_H
