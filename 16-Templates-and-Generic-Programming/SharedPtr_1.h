//
// Created by CottonCandyZ on 3/17/22.
//

#ifndef C__PRIMER_SHAREDPTR_1_H
#define C__PRIMER_SHAREDPTR_1_H

#include <algorithm>

template<typename T>
class SharedPtr {
    using DelFuncPtr = void (*)(const T *);
public:
    explicit SharedPtr(T *_ptr = nullptr, DelFuncPtr _del = nullptr) :
            ptr(_ptr), ref_count(new size_t(ptr != nullptr)), del(_del) {}

    SharedPtr(const SharedPtr &rhs) : ptr(rhs.ptr), ref_count(rhs.ref_count), del(rhs.del) {
        ++*ref_count;
    }

    SharedPtr(SharedPtr &&rhs) noexcept: SharedPtr() {
        swap(rhs);
    }

    void swap(SharedPtr &r) noexcept {
        using std::swap;
        swap(ptr, r.ptr);
        swap(ref_count, r.ref_count);
        swap(del, r.del);
    }

    SharedPtr &operator=(const SharedPtr &rhs) {
        if (this != &rhs) {
            if (--*ref_count == 0) {
                free();
            }
            ptr = rhs.ptr;
            ref_count = rhs.ref_count;
            del = rhs.del;
            ++*ref_count;
        }

    }

    SharedPtr &operator=(SharedPtr &&rhs) noexcept {
        if (&rhs != this) {
            if (--*ref_count == 0) {
                free();
            }
            *this = SharedPtr();
            swap(rhs);
        }
    }

    void free() {
        if (--*ref_count == 0) {
            del ? del(ptr) : delete ptr;
            delete ref_count;
        }
        ptr = nullptr;
        ref_count = nullptr;
        del = nullptr;
    }

    ~SharedPtr() {
        if (!ptr) return;
        free();
    }


    T *get() const noexcept { return ptr; }

    T &operator*() const noexcept { return *get(); }

    T *operator->() const noexcept { return get(); }

    size_t use_count() const noexcept { return *ref_count; }

    explicit operator bool() const noexcept { return ptr != nullptr; }


private:
    T *ptr;
    size_t *ref_count;
    DelFuncPtr del;
};

#endif //C__PRIMER_SHAREDPTR_1_H
