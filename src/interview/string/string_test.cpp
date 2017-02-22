//
// Created by zhuanxu on 17/2/15.
//

#include <string>
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
namespace str01 {
    // https://wizardforcel.gitbooks.io/the-art-of-programming-by-july/content/01.01.html
    void reverseString(char *s, int m, int n){
        while(m<n){
            swap(s[m++],s[n--]);
        }
    }

    void leftShiftOne(char *s, int n){
        char t = s[0];
        for (int i=0; i<n-1;i++){
            s[i] = s[i+1];
        }
        s[n-1] = t;
    }
    // 字符串旋转
    // abcdef => def abc
    void leftRotateString(char *s, int n, int m) {
        while(m-->0){
            leftShiftOne(s,n);
        }
    }
    void test_rotate1(){
        char source[] = "abcdef";
        cout << "before: " << source;
        leftRotateString(source, 6, 3);
        cout << " after: " << source << endl;
    }
    void test_rotate2(){
        char source[] = "abcdef";
        cout << "before: " << source;
        reverseString(source,0,2);
        reverseString(source,3,5);
        reverseString(source,0,5);
        cout << " after: " << source << endl;
    }
}

namespace str02{
// https://wizardforcel.gitbooks.io/the-art-of-programming-by-july/content/01.02.html
// 字符串包含
    // hash 方案
    bool StringContain(string &a,string &b) {
        int hash = 0;
        for( auto c : a){
            hash |= 1 << (c - 'A');
        }
        for (auto c : b) {
            if (!(hash & 1 << (c - 'A'))) {
                return false;
            }
        }
        return true;
    }

    void test_contain() {
        string a = "ABCD";
        string b = "AA";
        assert(StringContain(a, b));
    }
}

namespace str03 {
    // 字符串转换成整数
    // https://wizardforcel.gitbooks.io/the-art-of-programming-by-july/content/01.03.html
    int StrToInt(const char *str, int n){
        // "123" => 123
        int value = 0;
        int i = 0;
        while (i<n){
            value = value * 10 + str[i] - '0';
            i++;
        }
        return value;
    }
    void test_str2int(){
        string val = "123";
        cout << "string: " << val << " int: " << StrToInt(val.c_str(),3);
    }
}
//回文判断
namespace str04 {
//
    // https://wizardforcel.gitbooks.io/the-art-of-programming-by-july/content/01.04.html
    bool IsPalindrome(const char *s, int n) {
        assert(s != nullptr);assert(n>0);
        int i =0;
        int j = n-1;
        while(i<j){
            if (s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void test_palindrome() {
        assert(IsPalindrome("abasdedsaba",11));
    }
}
//最长回文子串
namespace str05 {
    // https://wizardforcel.gitbooks.io/the-art-of-programming-by-july/content/01.05.html
    // 上面的代码太粗糙了
    int LongestPalindrome(const char *s, int n) {
        // case 1: "abac
        // 思路从每个开始，左右开弓，然后计算最长的长度
        // 分奇数 和 偶数 两种情况
        int max = 0;
        int c = 0;
        for (int i = 0; i <n; i++) {
            for (int j=0; (i-j)>0 && (i+j)<n; j++) {
                if (s[i-j] != s[i+j]){
                    break;
                }
                c = 2 * j + 1;
            }
            if (c > max){
                max = c;
            }
            for (int j=0;(i-j)>0 && (i+j+1) < n;j++){
                if (s[i-j] != s[i+j+1]){
                    break;
                }
                c = 2 * j + 2;
            }
            if (c > max){
                max = c;
            }
        }
        return max;
    }
    int LongestPalindromeImprove1(const char *s, int n){
        // 拉马车算法
        // prepare string
        string prepared;
        for(int i =0;i<n;i++) {
            prepared += "#";
            prepared += s[i];
        }
        prepared += "#";

//        cout << prepared << " lenght: " << prepared.length() << endl;
        vector<int> P(prepared.length(),0);

        int center = 0;
        P[center] = 1;
        int right = 0;
        for (int i=1;i<prepared.length();i++){
            right = center + P[center] - 1;
            if (i < right) {
                P[i]  = min(P[2*center-i],center+P[center]-i);
            }
            else {
                P[i]  = 1;
            }
            while(prepared[i-P[i]] == prepared[i+P[i]]){
                P[i]++;
            }
            if (P[i] >= P[center]){
                center = i;
            }
        }
        cout << endl;
        for (auto i : prepared){
            cout << i << " ";
        }
        cout << endl;
        for (auto i : P){
            cout << i << " ";
        }
        cout << endl;
        return P[center] - 1;
    }

    void test_long_palindrome() {
//        cout << "\ntest_long_palindrome: " << LongestPalindrome("abac",4) << endl;
//        cout << "improve method: " << LongestPalindromeImprove1("abac",4);
        string a = "12212321";
        assert(LongestPalindrome(a.c_str(), (int) a.length())  == LongestPalindromeImprove1(a.c_str(), (int) a.length()));
    }
}
// 字符串的全排列
#include <cassert>
namespace str06 {
    // https://wizardforcel.gitbooks.io/the-art-of-programming-by-july/content/01.06.html
    // case：
    // 输入abc
    // 输出：abc、acb、bac、bca、cab 和 cba
    void CalcAllPermutation(char* perm, int from, int to){
        if (from == to) {
            for (int i=0;i<from;i++){
                cout << perm[i];
            }
            cout << endl;
            return;
        }
        for(int i=from;i<to;i++){
            char t = perm[from];
            perm[from] = perm[i];
            perm[i] = t;
            CalcAllPermutation(perm,from+1,to);
        }
    }
    void CalcAllPermutation1(char* perm,int n){
        // 思路：以找 21543 为例子
        // 21543 -> 23145 -> 23154 -> 23415 -> 23451 -> 23514 -> 23541 -> 24135
        // 所以我们可以看上面的流程
        // AxB B中有比x大的 从B中找到最小的一个比x大的 得到  AyB' ，此时 B'是降序，将其反转 于是就有 AyB''
        //[0,n-1]
        int i=0,j =0;
        for(i=n-1;i>0;i--){
            if (perm[i-1] < perm[i]) {
                break;
            }
        }
        if (i==0){
            return;
        }
        assert(i>0 && i<n);
        // 此时 [i,n-1]都是降序
        // perm[i-1] < perm[i]
        // 下一步从 [i,n-1] 找到第一个大于 perm[i-1]的数
        for (j=n-1;j>i;j--){
            if (perm[j] > perm[i-1]){
                break;
            }
        }
        assert(j>=i && j<n);
        swap(perm[i-1],perm[j]);
        // reverse [i,n-1]
        for(int m=i,l=n-1;m<l;m++,l--){
            swap(perm[m],perm[l]);
        }
        cout << string(perm) << endl;
        CalcAllPermutation1(perm,n);
        return;
    }
    void test_all_permutation() {
        char test[] = "abc";
        CalcAllPermutation(test,0,3);
        cout << "method 2:"<<endl;
        char test1[] = "21543";
//        char test1[] = "54321";
        CalcAllPermutation1(test1,5);
    }
}

int main() {
    str01::test_rotate1();
    str01::test_rotate2();
    str02::test_contain();
    str03::test_str2int();
    str04::test_palindrome();
    str05::test_long_palindrome();
    str06::test_all_permutation();
}