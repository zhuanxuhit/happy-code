//
// Created by zhuanxu on 17/3/11.
//
#include <boost/operators.hpp>
#include <iostream>
using namespace std;

// 参考：https://theboostcpplibraries.com/boost.operators
class Circle :
        boost::less_than_comparable<Circle> { // 自动推导： operator>, operator<=, and operator>=
public:
    Circle(double radius) : radius(radius) {}
    bool operator<(const Circle&other) const{
        return radius < other.radius;
    }
    bool operator==(const Circle&other) const{
        return radius == other.radius;
    }
private:
    double radius;

};

int main() {
    Circle c1(2);
    Circle c2(2);
    Circle c3(3);
    Circle c4(4);
    cout << (c1 < c2) << endl;
    cout << (c1 <= c2) << endl;
    cout << (c1 == c2) << endl;
}