//
// Created by zhuanxu on 17/3/15.
//


#include <memory>
#include <iostream>

using namespace std;

class Foo{
public:

private:
    int a_;
    int b_;
};

void good_create_practise() {
    // since c++11
    // 使用 make_shared 能让一次性申请内存，（资源和引用一起）
    shared_ptr<int> sp1 = make_shared<int>(12);
    (*sp1)++;
    cout << *sp1 << endl;
}

int main() {
    good_create_practise();
}
