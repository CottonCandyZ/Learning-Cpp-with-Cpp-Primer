//
// Created by CottonCandyZ on 3/12/22.
//

#ifndef C__PRIMER_STRBLOB_7_H
#define C__PRIMER_STRBLOB_7_H

#include <vector>
#include <string>

class StrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;

    friend bool operator==(const StrBlob &, const StrBlob &);

    friend bool operator!=(const StrBlob &, const StrBlob &);

    friend bool operator<(const StrBlob &, const StrBlob &);
    friend bool operator>(const StrBlob &, const StrBlob &);
    friend bool operator<=(const StrBlob &, const StrBlob &);
    friend bool operator>=(const StrBlob &, const StrBlob &);

public:
    using size_type = std::vector<std::string>::size_type;

    StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

    StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

    StrBlob(const StrBlob &orig) :
            data(std::make_shared<std::vector<std::string>>(*orig.data)) {}

    StrBlob &operator=(const StrBlob &right) {
        data = std::make_shared<std::vector<std::string>>(*right.data);
        return *this;
    }

    std::string &operator[](size_t n);
    const std::string &operator[](size_t n) const;

    size_type size() const { return data->size(); };

    bool empty() const { return data->empty(); }

    void push_back(const std::string &t) { data->push_back(t); }

    void push_back(std::string &&);

    void pop_back();

    std::string &front();

    std::string &back();

    std::string &front() const;

    std::string &back() const;

    StrBlobPtr begin();

    StrBlobPtr end();

private:
    std::shared_ptr<std::vector<std::string>> data;

    void check(size_type i, const std::string &msg) const;

};

void StrBlob::check(size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}

std::string &StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string &StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

std::string &StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string &StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

void StrBlob::push_back(std::string &&s) {
    data->push_back(std::move(s));
}

bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
    return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs) {
    return std::lexicographical_compare(lhs.data->begin(), lhs.data->end(),
                                        rhs.data->begin(), rhs.data->end());
}

bool operator>(const StrBlob &lhs, const StrBlob &rhs) {
    return rhs < lhs;
}

bool operator<=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(rhs < lhs);
}

bool operator>=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs < rhs);
}

std::string &StrBlob::operator[](size_t n) {
    check(n, "out of range");
    return (*data)[n];
}
const std::string &StrBlob::operator[](size_t n) const {
    check(n, "out of range");
    return (*data)[n];
}


#endif //C__PRIMER_STRBLOB_7_H
