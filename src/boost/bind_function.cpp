//
// Created by zhuanxu on 17/3/11.
//

#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <iostream>
using namespace std;

class Foo {
public:
    void memberFunc(double d,int i, int j) {
        cout << d << endl;
        cout << i << endl;
        cout << j << endl;
    }
};

int main() {
    Foo foo;
    boost::function<void(int)> fp = boost::bind(&Foo::memberFunc,&foo,100,_1,5);
    boost::function<void(double,int)> fp2 = boost::bind(&Foo::memberFunc,&foo,_1,_2,30);
    boost::function<void(double,int)> fp3 = boost::bind(&Foo::memberFunc,boost::ref(foo),_1,1,_2);
    fp(10);
    fp2(0.5,20);
    fp3(0.3,10);
}