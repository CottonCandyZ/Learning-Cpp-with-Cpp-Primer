//
// Created by CottonCandyZ on 3/8/22.
//

#ifndef C__PRIMER_STRING_1_H
#define C__PRIMER_STRING_1_H

#include <memory>
#include <algorithm>
#include <iostream>

class String {
public:
    String() : String("") {}

    String(const char *);

    String(const String &);

    String &operator=(const String &);

    ~String();

    const char *c_str() const { return elements; }

    size_t size() const { return end_e - elements; }

    size_t length() const { return end_e - elements - 1; }

    char *begin() const { return elements; }

    char *end() const { return end_e; }

private:
    using allo = std::allocator_traits<std::allocator<char>>;

    std::pair<char *, char *> alloc_n_copy(const char *, const char *);

    void alloc_range(const char *, const char *);

    void free();

    char *elements;
    char *end_e;
    std::allocator<char> alloc;
};

std::pair<char *, char *> String::alloc_n_copy(const char *b, const char *e) {
    auto data = allo::allocate(alloc, e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

// 复制
void String::alloc_range(const char *b, const char *e) {
    auto newdata = alloc_n_copy(b, e);
    elements = newdata.first;
    end_e = newdata.second;
}

void String::free() {
    if (elements) {
        std::for_each(elements, end_e,
                      [this](char &p) { allo::destroy(alloc, &p); });
        allo::deallocate(alloc, elements, end_e - elements);
    }
    std::cout << "destroy" << std::endl;
}

String::~String() { free(); }

String &String::operator=(const String &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    end_e = data.second;
    return *this;
}

String::String(const String &s) {
    alloc_range(s.begin(), s.end());
}

String::String(const char *s) {
    alloc_range(s, s + strlen(s));
}

#endif //C__PRIMER_STRING_1_H
