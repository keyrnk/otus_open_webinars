#include "pretty.h"
#include "utils.h"

#include <functional>
#include <memory>

template <typename T>
class unique_ptr {
    T *ptr;

  public:
    unique_ptr(T *ptr_) : ptr{ptr_} {}
    ~unique_ptr() { delete ptr; }

    unique_ptr(const unique_ptr<T> &) = delete;
    unique_ptr<T> &operator=(const unique_ptr<T> &) = delete;

    unique_ptr(unique_ptr<T> &&other) : ptr{other.ptr} { other.ptr = nullptr; }
    unique_ptr<T> &operator=(unique_ptr<T> &&other) {
        ptr = other.ptr;
        other.ptr = nullptr;
        return *this;
    };

    T *get() { return ptr; }

    T *operator->() { return ptr; }
    T& operator*() { return *ptr; }
};

void unique_ptr_example() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    unique_ptr<int> ptr1(new int{41});
    //unique_ptr<int> ptr2 = ptr1;
    unique_ptr<int> ptr2(std::move(ptr1));
    std::cout << *ptr2 << std::endl;
}

class MyClass
{
public:
    MyClass(int value)
        : m_value(value)
    {}

    int GetValue() const
    {
        return m_value;
    }

private:
    int m_value;
};

void extended_unique_ptr_example()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::unique_ptr<MyClass> ptr; //nullptr
    std::unique_ptr<MyClass> ptr2(new MyClass(10));
    std::cout << "MyClass value " << ptr2->GetValue() << std::endl;

    std::cout << "MyClass value " << (*ptr2).GetValue() << std::endl;

    ptr2.reset();
    //std::cout << "MyClass value " << ptr2->GetValue(); //BAD!

    ptr2.reset(new MyClass(5));
    std::cout << "MyClass value " << ptr2->GetValue() << std::endl;

    ptr.reset(new MyClass(7));
    ptr2.swap(ptr);
}

class A {
  public:
    A() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    ~A() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

struct deleter {
    void operator()(A *ptr) { delete ptr; }
};

void delete_A(A *ptr) { delete ptr; }

void size_of() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    A *raw_ptr = nullptr;

    std::unique_ptr<A> ptr1(new A);

    std::unique_ptr<A, deleter> ptr2(new A);
    
    std::unique_ptr<A, void(*)(A*)> ptr3(new A, delete_A);

    PRETTY_COUT(sizeof(raw_ptr), sizeof(ptr1), sizeof(ptr2), sizeof(ptr3));
}

int main(int argc, char *argv[]) {
    // unique_ptr_example();
    //extended_unique_ptr_example();
    size_of();
    // make_unique_example();
    return 0;
}
