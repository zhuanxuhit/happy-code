//
// Created by 汪超 on 2020/7/17.
//

#include <cstdio>
#include <utility>

struct shape {
};

void foo(const shape &) {
    puts("foo(const shape&)");
}

void foo(shape &&) {
    puts("foo(shape&&)");
}

//void bar(const shape &s) {
//    puts("bar(const shape&)");
//    foo(s);
//}
//
//void bar(shape &&s) {
//    puts("bar(shape&&)");
//    foo(s);
//}

template<typename T>
void bar(T &&s) {
    foo(std::forward<T>(s));
}

int main() {
    bar(shape());
    {
        shape temp;
        bar(temp);
    }
}