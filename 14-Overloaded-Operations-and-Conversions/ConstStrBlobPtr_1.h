//
// Created by CottonCandyZ on 3/12/22.
//

#ifndef C__PRIMER_CONSTSTRBLOBPTR_1_H
#define C__PRIMER_CONSTSTRBLOBPTR_1_H

#include <vector>
#include <string>

class ConstStrBlobPtr;

class StrBlob {
    friend class ConstStrBlobPtr;

public:
    using size_type = std::vector<std::string>::size_type;

    StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

    StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

    size_type size() const { return data->size(); };

    bool empty() const { return data->empty(); }

    void push_back(const std::string &t) { data->push_back(t); }

    void pop_back();

    std::string &front();

    std::string &back();

    std::string &front() const;

    std::string &back() const;

    ConstStrBlobPtr begin() const; // 添加 const

    ConstStrBlobPtr end() const; // 添加 const

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

class ConstStrBlobPtr {
public:

    ConstStrBlobPtr() : curr(0) {}

    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {} // 添加 const

    const std::string &deref() const; // 返回值添加 const

    ConstStrBlobPtr &incr();

    bool operator!=(const ConstStrBlobPtr &p) { return p.curr != curr; } // 增加一个函数，方便 20 题的自增

    const std::string &operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    const std::string *operator->() {
        return &this->operator*();
    }

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
std::shared_ptr<ConstStrBlobPtr::vec_string> ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound ConstStrBlobPtr");
    if (i >= ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret;
}

/**
 * 得到当前 curr 指向位置的引用，在越界时跑出一个异常
 * @return 当前 curr 指向位置的引用
 */
const std::string &ConstStrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

/**
 * 递增当前 curr 指向的位置
 * @return 返回该类自身的引用
 */
ConstStrBlobPtr &ConstStrBlobPtr::incr() {
    check(curr, "increment past end of ConstStrBlobPtr");
    ++curr;
    return *this;
}

ConstStrBlobPtr StrBlob::begin() const {
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const {
    auto ret = ConstStrBlobPtr(*this, data->size());
    return ret;
}


#endif //C__PRIMER_CONSTSTRBLOBPTR_1_H
