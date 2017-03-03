//
// Created by zhuanxu on 17/3/3.
//

#include <queue>
#include <iostream>
using namespace std;
// 验证优先级队列

int main() {
    priority_queue<int,vector<int>,greater<int>> q; // 小堆
    priority_queue<int,vector<int>,less<int>> q2; // 大堆
    int nums[] = {3,1,21,421,1,21};
    for(auto n : nums){
        q.push(n);
    }
    while (!q.empty()){
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}