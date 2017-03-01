//
// Created by zhuanxu on 17/3/1.
//


// traits 萃取机：丢给他东西能够萃取出你想要的特征
// 针对 iterator 就有 iterator traits
// 针对 type 就有 type traits

// Iterator 需要遵循的原则
// iterator 是 算法 和 容器 连接的桥梁
// 算法会像迭代器询问一些属性，以此来对容器做出最优的操作
// 具有的属性有：
// iterator_category ： 不同的分类会有不同的性质，譬如有的能 ++，有的不能 -- 等
// difference_type ：代表的是两个迭代器之间的距离用什么表示
// value_type ：代表的容器中值的类型
// 这种 iterator 需要回答算法的问题的有5种，前面介绍了3种，还有2种是：pointer, reference，暂时从未使用过

//
#include <array>

using namespace std;
int main() {
    array<int,2> a = {1,2};
//    array<int,2>::iterator
//    a.begin()
    typedef typename iterator_traits<decltype(a.begin())>::value_type v2;

}
