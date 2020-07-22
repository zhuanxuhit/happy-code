//
// Created by 汪超 on 2020/7/9.
//
#include <iostream>

using namespace std;

struct A {
    A(int i) { cout << "A:" << i << endl; }

    A(int i, int j) { cout << "A:" << i << " " << j << endl; }

    A(float i = 1.1, int j = 2) { cout << "A:" << i << " " << j << endl; }

    void f(double i) {
        cout << "A:" << i << endl;
    }
};

struct B : A {
    explicit B(int i) : A(i), d(i) {
        cout << "B" << endl;
    }

    using A::A;

    using A::f;

    void f(int i) {
        cout << "B:" << i << endl;
    }

    int d{0};

    friend ostream &operator<<(ostream &stream, const B &b) {
        stream << b.d << endl;
        return stream;
    }
};

int main() {
    B b1(1);
    b1.f(1.0);
    b1.f(1);

//    cout << b << endl;
    B b2(3, 4);
    B b3;
    B b4((float)2.1, 2);
}