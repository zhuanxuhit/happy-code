//
// Created by zhuanxu on 17/2/28.
//
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

// 对于 k = mp[j] 代表的是：[0,j) 都相等，下一步要比较 p[k] = p[j]

void preKmp(const char*p,int m, int kmpNext[]){
 // mp算法是怎么回事呢？
    int j = 0;
    int k = kmpNext[j] = -1;
    while(j < m){
        while (k > -1 && p[k] != p[j]){
            k = kmpNext[k];
        }
        // 此处结束的条件是 k == -1 || p[k] = p[j]
        // 如果p[k] == p[j]，那下一个比较的就是 p[k+1] p[j+1]
        // 如果 k == -1，则表示下一个要比较的是 p[k+1] p[0]
//        kmpNext[++j] = ++k;
        k++;
        j++;
        if (p[k] == p[j]){
            kmpNext[j] = kmpNext[k];
            // 此处再j增加的过程中，由于一旦发现 p[k] == p[j] 都会去更新  kmpNext[j] 所以确保了进行一次
            // kmpNext[j] = kmpNext[k] 就不会改变了
        }else {
            kmpNext[j] = k;
        }
        // 此处 kmp算法进行更进一步比较，直接比较 p[k+1] p[j+1] 如果相等，则更新 kmpNext[j+1] = kmpNext[k+1]
    }
}

int KMP(string p, string t){
    int m = p.length();
    int n = t.length();

    if ( n < m){
        cerr << "Unsuccessful match!"<< endl;
        return -1;
    }
    const char * x = p.c_str();
    const char * y = t.c_str();

    int i=0,j=0,kmpNext[m+1];
    preKmp(x,m,kmpNext);
    i = 0;
    j = 0;
    while (i<n){
        while (j!=-1 && p[j] != t[i]) {
            j = kmpNext[j];
        }
        i++;
        j++;
        if (j == m){
            cout << "Matching index found at: " << i - m << endl;
            return (i - m);
        }
    }
    return -1;
}

void printResult(string p, string t){
    int pos = KMP(p, t);
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

    cout<<"KMP : "<<endl;
    printResult(p1,t);
    printResult(p2,t);
    printResult(p3,t);
    cout<<endl;
}