#include <stdio.h>  // puts
#include "shape.h"  // shape/circle/triangle

class result {
public:
    result() { puts("result()"); }
    ~result() { puts("~result()"); }
};

result process_shape(const shape& shape1, const shape& shape2)
{
    puts("process_shape()");
    return result();
}

int main()
{
    puts("main()");
    result&& r = process_shape(circle(), triangle());
    // 下面这种用法并不会延长 result 的生命周期。
    // 我们仍然有一个有效的变量 r，但它指向的对象已经不存在了，对 r 的解引用是一个未定义行为。由于 r 指向的是栈空间，通常不会立即导致程序崩溃，而会在某些复杂的组合条件下才会引致问题
    // https://time.geekbang.org/column/article/169268
//    result&& r = std::move(process_shape(circle(), triangle()));
    puts("something else");
}
