//
// Created by zhuanxu on 17/3/12.
//

//
// Created by zhuanxu on 17/3/12.
//

#include <stdio.h>
#include <cassert>

void foo(int x)
{
}

class B
{
public:
    virtual void foo()
    {
    }
};

class D : public B
{
public:
    void foo(int x)
    {
    }
};

template<typename To, typename From>
inline To down_cast(From *f) {
    assert(f== nullptr || dynamic_cast<To>(f) != nullptr);

    return static_cast<To>(f);
}

int main(void)
{
    int n;
    double d = 1.23;
    n = d; // 隐式转换

    B* pb = new D;
    D* pd ;

//    pb = pd; // 此处没有问题，因为将子类转换为父类
    pd = down_cast<D*>(pb);// 但是将父类转换为子类，却可能是有问题的，需要我们检查

    delete pd;
//    {// bad case
//        B* pb = new B;
//        D* pd  = down_cast<D*>(pb);
//        delete pb;
//    }

    return 0;
}