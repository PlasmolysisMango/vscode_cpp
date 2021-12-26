#ifndef MY_SHARED_PTR
#define MY_SHARED_PTR
#include <utility>

template <typename T>
class MySharedPtr {
public:
    MySharedPtr() : p(nullptr), ref_cnt_p(nullptr) { }
    MySharedPtr(const MySharedPtr &msp): p(msp.p), ref_cnt_p(msp.ref_cnt_p) 
    {
        if (ref_cnt_p)
            ++*ref_cnt_p;
    }
    explicit MySharedPtr(T *t) : p(t), ref_cnt_p(new size_t(1)) { }
    MySharedPtr &operator=(const MySharedPtr &);
    ~MySharedPtr();

    explicit operator bool() const { return p ? true : false; }
    // T &operator*() { return *p; }
    T &operator*() const { return *p; }
    // T *operator->() { return &this->operator*(); }
    T *operator->() const { return &this->operator*(); }
    T *get() const { return p; }

private:
    T *p;
    size_t *ref_cnt_p;
    
};

template <typename T>
MySharedPtr<T>& MySharedPtr<T>::operator=(const MySharedPtr &rhs)
{
    if (rhs.ref_cnt_p)
        ++*rhs.ref_cnt_p;
    if (ref_cnt_p && --*ref_cnt_p == 0) {
        delete p;
        delete ref_cnt_p;
    }
    p = rhs.p;
    ref_cnt_p = rhs.ref_cnt_p;
    return *this;
}

template <typename T>
MySharedPtr<T>::~MySharedPtr()
{
    if (ref_cnt_p && --*ref_cnt_p == 0) {
        delete p;
        delete ref_cnt_p;
    }
}

template <typename T, typename... Args>
MySharedPtr<T> make_MyShared(Args &&...args)
{
    return MySharedPtr<T>(new T(std::forward<Args>(args)...));
}

#endif