//
// Created by zhuanxu on 17/3/8.
//
#include <iostream>
#include <cassert>
#include <deque>
#include <queue>

using namespace std;

// 找到第 n 个ugly number
class Solution {
public:
    int nthUglyNumber_v1(int n) {
        assert(n>=1 && n<=1690);
        if (n == 1){
            return 1;
        }
        // 定义一个优先级队列,问题是优先级队列会重复。尴尬
        priority_queue<int,vector<int>,greater<int>> q; // 小堆
        q.push(2);
        q.push(3);
        q.push(5);
        int uglyn = 0;
        while (--n>0){
            uglyn = q.top();
            q.pop();

            q.push(uglyn*2);
            q.push(uglyn*3);
            q.push(uglyn*5);
        }
        return uglyn;
    }


    int nthUglyNumber_v2(int n) {
        assert(n>=1 && n<=1690);
        if (n == 1){
            return 1;
        }
        // 定义3个队列，每次都是从队列头出
        deque<int> d1;
        deque<int> d2;
        deque<int> d3;
        d1.push_back(2);
        d2.push_back(3);
        d3.push_back(5);
        int uglyn=0;
        while (--n){
            int n1 = d1.front();
            int n2 = d2.front();
            int n3 = d3.front();
            uglyn = min(min(n1,n2),n3);
            if (uglyn==n1){
                d1.pop_front();
            }
            if (uglyn==n2){
                d2.pop_front();
            }
            if (uglyn==n3){
                d3.pop_front();
            }
            d1.push_back(uglyn*2);
            d2.push_back(uglyn*3);
            d3.push_back(uglyn*5);
        }
        return uglyn;
    }
    // 太浪费了，直接用数组实现
    int nthUglyNumber_v3(int n) {
        // 可以用指针的思路
        vector<int> v(1,1);// size, value
        int i2=0,i3=0,i5=0;
        while(--n>0){
            int n2 = v[i2]*2;
            int n3 = v[i3]*3;
            int n5 = v[i5]*5;
            int nn = min(n2,min(n3,n5));
            if (nn == n2) i2++;
            if (nn == n3) i3++;
            if (nn == n5) i5++;
            v.push_back(nn);
        }
        return v.back();
    }
};
int main() {
    Solution s;
    cout << s.nthUglyNumber_v3(10) << endl;
    cout << s.nthUglyNumber_v3(7) << endl;
}
