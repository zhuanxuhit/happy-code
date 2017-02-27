//
// Created by zhuanxu on 17/2/27.
//
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

// 此处 k = mpNext[j] 表示的是 x[j] == x[k] k==-1表示没有匹配的
void preMp(const char *p,int m, int mpNext[]){
    int j=0;
    int k = mpNext[j] = -1;
    // 考虑边界条件
//    assert(k<j);assert(j<m);
//    while (j+1<m){
//        k++; // 代表下一个进行检查的下标
//        j++;
//        while( k > -1 && p[j]!=p[k]){ // 此处结束条件是 k == -1
//            // 如果此处 k == 0了，表示没有匹配了
//            if (k == 0){
//                k--;
//                break;
//            }else {
//                k = mpNext[k-1];
//                k++;
//            }
//        }
//        mpNext[j] = k;
//    }
    // 版本2，上面一个版本太冗余，怎么改进下
    // 其实总结上面的版本，我们会发现在主要复杂的地方在于 k == -1 不是终结条件
    // 假设我们将 k = mpNext[j] 定义为下一个要比较的 p[k]，那么一旦 p[k] == -1 则终止
//    j = 1;
//    k = 0;
//    while(j<m){
//        while (k>-1 && p[j] != p[k]){
//            k = mpNext[k];
//        }
//        mpNext[j++] = ++k;
//    }
    // 版本3,在怎么优化下呢？
    // 我们此处认为 k = mpNext[j] 代表的是 前面 0 - j-1个字符是匹配的，下面要比较的是 p[j] 和 p [k]
    assert(k<j);assert(j<m);
    while(j<m){
        while(k>-1 && p[j] != p[k]){
            k = mpNext[k];
        }
        mpNext[++j] = ++k;
    }
    // k = mpNext[j]
    // 上面式子的含义是：p[0:j] 共 j 个字符已经匹配，下面比较
    // p[j] 和  p[k]
}

// pattern, target
int MP(string p, string t){
    int m = (int) p.length();
    int n = (int) t.length();
    if (m > n){
        cerr << "Unsuccessful match!"<< endl;
        return -1;
    }
    const char * x = p.c_str();
    const char * y = t.c_str();

    int i=0,j=0,mpNext[m+1];
    preMp(x,m,mpNext);

//    for (int i=0;i<m;i++){
//        cout << mpNext[i] << endl;
//    }
    j = 0;
    i = 0;
    while(i<n){
        assert(j>-1 && j<m);
        assert(i>-1 && i<n);
        while(j != -1 && p[j] != t[i]) {
            j = mpNext[j];
        }
        // 退出条件：p[j] == t[i] 或者 j == -1 都是下面的操作
        i++;
        j++;
        if (j == m){
            cout << "Matching index found at: " << i - m << endl;
            return (i - m);
        }

//        while(j<m && p[j] == t[i]){
//            j++;
//            i++;
//        }
//        // 退出条件 j == m
//        if (j == m){
//            cout << "Matching index found at: " << i - m << endl;
//            return (i - m);
//        }
//        // 退出条件：p[j] != t[i]
//        j = mpNext[j];
//        if (j == -1) {
//            i++;
//            j++;
//        }
    }
    return  -1;
}


void printResult(string p, string t){
    int pos = MP(p, t);
    if (pos != -1){
        cout << "target string : " << t << endl;
        cout << "pattern string: " << string(pos,' ') << p << endl;
    }else {
        cout << "can't find "<<p << " in string: "<<t<<endl;
    }
}

int main() {
    string p1 = "abcabcad";
    string p2 = "adcadcad";
    string p3 = "ababcaabc";
    string t = "ctcabcabcadtcaabcabcadat";

    cout<<"MP : "<<endl;
    printResult(p1,t);
    printResult(p2,t);
    printResult(p3,t);
    cout<<endl;
}