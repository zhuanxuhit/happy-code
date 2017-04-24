//
// Created by zhuanxu on 17/4/6.
//

#include <iostream>
#include <memory>

struct Foo {
    Foo() { std::cout << "Foo::Foo\n"; }
    ~Foo() { std::cout << "Foo::~Foo\n"; }
    void bar() { std::cout << "Foo::bar\n"; }
};

void f(const Foo &foo)
{
    std::cout << "f(const Foo&)\n";
}

int main()
{
    std::unique_ptr<Foo> p1(new Foo);  // p1 拥有 Foo
    if (p1) p1->bar();

    {
        std::unique_ptr<Foo> p2(std::move(p1));  // 现在 p2 拥有 Foo
        f(*p2);

        p1 = std::move(p2);  // 所有权还给了 p1
        std::cout << "destroying p2...\n";
    }

    if (p1) p1->bar();

    // p1 离开作用域时， Foo 实例会自动销毁
}