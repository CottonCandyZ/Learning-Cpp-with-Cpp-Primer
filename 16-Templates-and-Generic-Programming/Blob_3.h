//
// Created by CottonCandyZ on 3/17/22.
//

#ifndef C__PRIMER_BLOB_3_H
#define C__PRIMER_BLOB_3_H

#include <vector>
#include <string>
#include "SharedPtr_1.h"

template<typename T>
class BlobPtr;

template<typename T>
class Blob {
    friend class BlobPtr<T>;

    friend bool operator==(const Blob &, const Blob &);

    friend bool operator!=(const Blob &, const Blob &);

    friend bool operator<(const Blob &, const Blob &);

    friend bool operator>(const Blob &, const Blob &);

    friend bool operator<=(const Blob &, const Blob &);

    friend bool operator>=(const Blob &, const Blob &);

public:
    using size_type = typename std::vector<T>::size_type;

    Blob() : data(new std::vector<T>()) {}

    Blob(std::initializer_list<T> il) : data(new std::vector<T>(il)) {}

    template<typename It>
    Blob(It b, It e) : data(new std::vector<T>(b, e)) {}

    Blob(const Blob &orig) :
            data(new std::vector<T>(*orig.data)) {}

    Blob &operator=(const Blob &right) {
        data = new std::vector<T>(*right.data);
        return *this;
    }

    T &operator[](size_t n);

    const T &operator[](size_t n) const;

    size_type size() const { return data->size(); };

    bool empty() const { return data->empty(); }

    void push_back(const T &t) { data->push_back(t); }

    void push_back(T &&);

    void pop_back();

    T &front();

    T &back();

    T &front() const;

    T &back() const;

    BlobPtr<T> begin();

    BlobPtr<T> end();

private:
    SharedPtr<std::vector<T>> data;

    void check(size_type i, const std::string &msg) const;

};

template<typename T>
void Blob<T>::check(size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template<typename T>
T &Blob<T>::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

template<typename T>
T &Blob<T>::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

template<typename T>
T &Blob<T>::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

template<typename T>
T &Blob<T>::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

template<typename T>
void Blob<T>::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

template<typename T>
void Blob<T>::push_back(T &&s) {
    data->push_back(std::move(s));
}

template<typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs) {
    return *lhs.data == *rhs.data;
}

template<typename T>
bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs) {
    return !(lhs == rhs);
}

template<typename T>
bool operator<(const Blob<T> &lhs, const Blob<T> &rhs) {
    return std::lexicographical_compare(lhs.data->begin(), lhs.data->end(),
                                        rhs.data->begin(), rhs.data->end());
}

template<typename T>
bool operator>(const Blob<T> &lhs, const Blob<T> &rhs) {
    return rhs < lhs;
}

template<typename T>
bool operator<=(const Blob<T> &lhs, const Blob<T> &rhs) {
    return !(rhs < lhs);
}

template<typename T>
bool operator>=(const Blob<T> &lhs, const Blob<T> &rhs) {
    return !(lhs < rhs);
}

template<typename T>
T &Blob<T>::operator[](size_t n) {
    check(n, "out of range");
    return (*data)[n];
}

template<typename T>
const T &Blob<T>::operator[](size_t n) const {
    check(n, "out of range");
    return (*data)[n];
}

#endif //C__PRIMER_BLOB_3_H
