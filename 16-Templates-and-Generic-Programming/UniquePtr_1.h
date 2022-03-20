//
// Created by CottonCandyZ on 3/17/22.
//

#ifndef C__PRIMER_UNIQUEPTR_1_H
#define C__PRIMER_UNIQUEPTR_1_H

#include <memory>

class Delete {
public:
    template<typename T>
    void operator()(T *ptr) const { delete ptr; }
};


template<typename T, typename D = Delete>
class UniquePtr {
public:
    explicit UniquePtr(T *_ptr = nullptr, const D &_d = D()) noexcept: ptr(_ptr), del(_d) {}

    ~UniquePtr() { del(ptr); }

    UniquePtr(const UniquePtr &) = delete;

    UniquePtr &operator=(const UniquePtr &) = delete;

    UniquePtr(UniquePtr &&rhs) noexcept: ptr(rhs.ptr), del(std::move(rhs.del)) {
        rhs.ptr = nullptr;
    }

    UniquePtr &operator=(UniquePtr &&rhs) noexcept {
        if (&rhs != this) {
            reset();
            ptr = rhs.ptr;
            del = std::move(rhs.del);
            rhs.ptr = nullptr;
        }
        return *this;
    }

    T *release() noexcept {
        T *ret = ptr;
        ptr = nullptr;
        return ret;
    }

    void reset(T *q = nullptr) noexcept {
        del(q);
        ptr = q;
    }

    T *get() const noexcept { return ptr; }

    D &get_deleter() noexcept { return del; }

    const D &get_deleter() const noexcept { return del; }

    explicit operator bool() const noexcept { return ptr != nullptr; }

    T &operator*() const { return *ptr; }

    T *operator->() const noexcept { return ptr; }

    T &operator[](size_t i) const { return ptr[i]; }


private:
    T *ptr;
    D del;
};

#endif //C__PRIMER_UNIQUEPTR_1_H
