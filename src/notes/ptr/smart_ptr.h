//
// Created by 汪超 on 2020/7/14.
//

#ifndef HAPPY_CODE_SMART_PTR_H
#define HAPPY_CODE_SMART_PTR_H

#include <algorithm>
#include "shared_count.h"

template<typename T>
class smart_ptr {
public:
    // 模板的各个实例间并不天然就有 friend 关系，因而不能互访私有成员 ptr_ 和 shared_count_。
    template<typename U> friend
    class smart_ptr;

    explicit smart_ptr(T *ptr = nullptr) : ptr_(ptr) {
        if (ptr_) {
            shared_count_ = new shared_count();
        }
    }

    ~smart_ptr() {
        if (ptr_ && !shared_count_->reduce_count()) {
            delete shared_count_;
            delete ptr_;
        }
    }

    // 拷贝构造
    smart_ptr(const smart_ptr &other) {
        ptr_ = other.ptr_;
        if (ptr_) {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }

    // 拷贝构造，支持继承的指针拷贝
    template<typename U>
    smart_ptr(const smart_ptr<U> &other) noexcept {
        ptr_ = other.ptr_;
        if (ptr_) {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }

    // 移动构造, 如果提供了移动构造函数而没有手动提供拷贝构造函数，那后者自动被禁用
    smart_ptr(smart_ptr &&other) {
        ptr_ = other.ptr_;
        if (ptr_) {
            shared_count_ = other.shared_count_;
            other.ptr_ = nullptr;
        }
    }

    template<typename U>
    smart_ptr(const smart_ptr<U> &other, T *ptr) noexcept {
        ptr_ = ptr;
        if (ptr_) {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }


    // 赋值构造
//    smart_ptr &operator=(smart_ptr &rhs) {
//        smart_ptr(rhs).swap(*this);
//        return *this;
//    }
    // 合并赋值构造和move赋值
    smart_ptr &operator=(smart_ptr rhs) {
        rhs.swap(*this);
        return *this;
    }


    // 支持 * 解引用
    T &operator*() const { return *ptr_; }

    // 支持 -> 运算符指向对象成员
    T *operator->() const { return ptr_; }

    // 能像指针一样用在布尔表达式里
    operator bool() const { return ptr_; }

    T *get() const noexcept { return ptr_; }

    long use_count() const noexcept {
        if (ptr_) {
            return shared_count_->get_count();
        } else {
            return 0;
        }
    }

    T *release() {
        T *ptr = ptr_;
        ptr_ = nullptr;
        return ptr;
    }

    void swap(smart_ptr &rhs) {
        using std::swap;
        swap(ptr_, rhs.ptr_);
    }

private:
    T *ptr_;
    shared_count *shared_count_;
};


#endif //HAPPY_CODE_SMART_PTR_H
