//
// Created by zhuanxu on 17/3/2.
//
#include <iostream>
using namespace std;

// final表明该类不会被子类继承
struct Base final{
    virtual void fun(int){
        cout << "Base_fun_int" << endl;
    }
};
//struct Derived : Base {
//};

struct Base1{
    virtual void fun(int) final {
        cout << "Base_fun_int" << endl;
    }
};

struct Derived : Base1 {
//    virtual void fun(int)  {
//        cout << "Derived_fun_int" << endl;
//    }
};



int main() {
//    Derived d;
//    d.fun(1);
//    d.fun(1.0);
    float a = 1.0;
//    d.fun(a);
    Base b;
    b.fun(1);
}
