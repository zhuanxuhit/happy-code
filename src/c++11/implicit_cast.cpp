//
// Created by zhuanxu on 17/3/12.
//

#include <stdio.h>

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
inline To implicit_cast(From const &f) {
    return f;
}

int main(void)
{
    int n;
    double d = 1.23;
    n = d; // 隐式转换

    B* pb;
    D* pd = NULL;

    pb = pd;
//    pb = implicit_cast<B*, D*>(pd);
    pb = implicit_cast<B*, D*>(pd);
    return 0;
}