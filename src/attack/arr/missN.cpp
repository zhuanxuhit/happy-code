//
// Created by zhuanxu on 2018/1/31.
//

#include <algorithm>
#include <iostream>

using namespace std;

int FirstMissNumber(int *a, int N) {
    // 找到从1开始，第一个不在数组中的正整数
    // 循环不变式
    // A[0..i-1] 已经都在在正确的位置上，即 j=1..i-1 A[j] = j
    // 现在考察 A[i]
    // if A[i] = i，则继续
    // if A[i] < i，说明A[i]已经在A[1..i-1]中存在，丢弃
    // if A[i] > N, 不会出现在A[1.N]中，丢弃
    // if i<A[i]<=N，if A[A[i]] == A[i] ，丢弃 else A[A[i]] != A[i] 交换
    int *A = a - 1; // 下标从1开始
    int i=1;
    while(i<=N){
        if(A[i] == i){
            i++;
        }
        else if (A[i]<i || A[i] > N || A[A[i]] == A[i]) {
            swap(A[i],A[N]);
            N--;
        }else {
            swap(A[i],A[A[i]]);
        }
    }
    return i;
}

int main() {
    int a[]  = {3,5,1,2,-3,7,4,8};
    cout << FirstMissNumber(a, sizeof(a)/ sizeof(int)) << endl;
}
