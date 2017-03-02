//
// Created by zhuanxu on 17/3/2.
//
#include <iostream>
#include <type_traits>
using namespace std;
// noexcept 表示不会抛出异常，如果内部有异常没有处理的话，就会直接调用 std::terminate() 程序中断
// 此处 noexcept(参数) 其实还能制定参数， noexcept = noexcept(true)
int foo() noexcept {
    return 0;
}
int bar() noexcept(true){
    return 0;
}
class Swap{
private:
    int value;
public:
    Swap(int value) : value(value) {}

    void swap(Swap &b){
        int temp = b.value;
        b.value = value;
        value = temp;
    }

    int getValue() const {
        return value;
    }
};

// 此处指定了如果 a.swap(b) 没有异常 swap 就不会有异常
template <typename T>
void myswap(T&a,T&b)noexcept(noexcept(a.swap(b))){
    a.swap(b);
}

// 发生 grow 的container只有两种：vector 和 deque
// 在vector grow的时候，需要注意:只有 move constructor 和 move assignment 写了 noexcept 才会去调用
int main() {
    Swap s1(1);
    Swap s2(2);
    myswap(s1,s2);
    cout << s1.getValue() << endl;
    cout << s2.getValue() << endl;
}

