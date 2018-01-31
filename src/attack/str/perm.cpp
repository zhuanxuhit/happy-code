//
// Created by zhuanxu on 2018/1/29.
//

#include <vector>
#include <iostream>
#include "prettyprint.h"
using namespace std;

void Print(int *a,int size){
    vector<int> v(a,a+size);
    cout << v << endl;
}

// 1234 怎么能够输出所有的排列
void permutation(int *a,int size, int pos){
    if (pos == size-1){
        Print(a,size);
        return;
    }
    for (int i=pos;i<size;i++){
        swap(a[pos],a[i]);
        permutation(a,size,pos+1);
        swap(a[pos],a[i]);
    }
}
// 输出不重复的变量
void permutationNoDup(int *a,int size, int pos){
    // 1224
    if (pos == size-1){
        Print(a,size);
        return;
    }
    int dup[10] = {0};
    for (int i=pos;i<size;i++){
        if (dup[a[i]] > 0){
            // 说明已经放到过最前头
            continue;
        }
        dup[a[i]] = 1;
        swap(a[pos],a[i]);
        permutationNoDup(a,size,pos+1);
        swap(a[pos],a[i]);

    }
}

// 输出递增序列
// 21543 下一个序列==
// 从后往前找到第一个非降序列 x[i] < x[i+1], x[j]>=x[j+1] j=i+1,i+2,..n, x[j]开始是非递增的
// 找到 x[j] j>i中第一个大于i的数，将其与 x[i] 交换位置，然后 reverse x[i+1..n]
// 1224 下一个
//
bool GetNextPermutation(int *a, int size) {
    int pos = -1;
    for(int i=size-2;i>=0;i--){
        if (a[i] < a[i+1]){
            pos = i;
            break;
        }
    }
    if (pos == -1){
        return false;
    }
    for(int j=size-1;j>pos;j--){
        if (a[j] > a[pos]) {
            swap(a[j],a[pos]);
            break;
        }
    }
    reverse(a+pos+1,a+size);
    return true;
}

int main() {
//    int a[] = {1,2,3,4};
//    permutation(a,4,0);
    int b[] = {1,2,2,4};
    permutationNoDup(b,4,0);
    cout << "=========" << endl;
    Print(b,4);
    while (GetNextPermutation(b, 4)){
        Print(b,4);
    }
}
