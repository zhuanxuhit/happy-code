//
// Created by zhuanxu on 17/3/2.
//

// type alias 和 typedef 没有什么区别

int main() {
    // is same typedef void (*func)(int,int)
    using func = void(*)(int,int);
}