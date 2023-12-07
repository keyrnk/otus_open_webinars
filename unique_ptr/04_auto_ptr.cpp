#include <algorithm>
#include <iostream>
#include <vector>
#include <memory>

template <typename T>
class auto_ptr {
    T *ptr;

  public:
    explicit auto_ptr(T *ptr_) : ptr(ptr_) {}
    ~auto_ptr() { delete ptr; }

    T *operator->() { return ptr; }
    T &operator*() { return *ptr; }

    auto_ptr(auto_ptr &rhv) {
        ptr     = rhv.ptr;
        rhv.ptr = nullptr;
    }

    T &operator=(auto_ptr &rhv) {
        ptr     = rhv.ptr;
        rhv.ptr = nullptr;
        return *this;
    }
};

int main(int argc, const char *argv[]) {

    auto_ptr<int> ptr1(new int(5));
    auto_ptr<int> ptr2 = ptr1;

    std::vector<auto_ptr<int> > vecAutoPtrs;
    return 0;
}
