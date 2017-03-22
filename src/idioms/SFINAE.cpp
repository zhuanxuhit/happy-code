//
// Created by zhuanxu on 17/3/22.
//

// SFINAE 技术，即匹配失败不是错误
// Substitution Failure Is Not An Error
// http://blog.csdn.net/freeelinux/article/details/53429009
// 其作用是当我们在进行模板特化的时候，会去选择那个正确的模板，避免失败
// 看个具体的例子：


#include <cstdio>
#include <cstdint>

long multiply(int i, int j) { return i * j; }

template <class T>
typename T::multiplication_result multiply(T t1, T t2)
{
    return t1 * t2;
}
void testTypeCheck();
void testNoDestroy();
int main(void)
{
    multiply(4,5);
    testTypeCheck();
    testNoDestroy();
}
// 当我们编译的时候，会去匹配模板 multiply，但是由于我们不知道multiplication_result，根据
// Substitution Failure Is Not An Error ，于是我们就去选择函数 multiply
// 这种技术在代码中的一个大的用途就是在编译时期来确定某个 type 是否具有我们需要的性质，看代码
template <class T>
struct is_pointer
{
    template <class U>
    static char is_ptr(U *);

    template <class X, class Y>
    static char is_ptr(Y X::*);

    template <class U>
    static char is_ptr(U (*)());

    static double is_ptr(...);

    static T t;
    enum { value = sizeof(is_ptr(t)) == sizeof(char) };
};

// 通过定义4个重载的 is_ptr函数，3个是接受不同的指针参数，另一个则包括了其他的所有参数
// IntPtr 是一个变量指针
// FooMemberPtr 是一个成员属性指针
// FuncPtr 是一个函数指针



struct Foo {
    int bar;
};

void testTypeCheck() {
    typedef int * IntPtr;
    typedef int Foo::* FooMemberPtr;
    typedef int (*FuncPtr)();

    printf("%d\n",is_pointer<IntPtr>::value);        // prints 1
    printf("%d\n",is_pointer<FooMemberPtr>::value);  // prints 1
    printf("%d\n",is_pointer<FuncPtr>::value);       // prints 1
}

// 接着我们来看下 muduo 库中的一段代码：
template<typename T>
struct has_no_destroy {
    template<typename C>
    static char test(decltype(&C::no_destroy));


    template<typename C>
    static int32_t test(...);

    const static bool value = sizeof(test<T>(0)) == 1;
};
// 其作用就是用来判断是否有 no_destroy 函数

struct A {

};

struct B {
    void no_destroy(){}
};
struct C {
    int no_destroy;
};

struct D : B {

};

void testNoDestroy() {
    printf("%d\n",has_no_destroy<A>::value);
    printf("%d\n",has_no_destroy<B>::value);
    printf("%d\n",has_no_destroy<C>::value);
    printf("%d\n",has_no_destroy<D>::value);
}
