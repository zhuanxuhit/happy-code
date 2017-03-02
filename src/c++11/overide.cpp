//
// Created by zhuanxu on 17/3/2.
//
#include <iostream>
using namespace std;

// 明确指明 override 告诉编译器这个是覆盖父类的virtual function
struct Base {
    virtual void fun(int){
        cout << "Base_fun_int" << endl;
    }
};

struct Derived : Base {
    virtual void fun(float){ // 本意是覆写父类函数，由于写错了参数导致新的virtual function，通过override能够让编译器帮忙检查
        cout << "Derived_fun_float" << endl;
    }
    virtual void fun(int) override  {
        cout << "Derived_fun_int" << endl;
    }
};

int main() {
    Derived d;
    d.fun(1);
//    d.fun(1.0);
    float a = 1.0;
    d.fun(a);
    Base b;
    b.fun(1);
}
