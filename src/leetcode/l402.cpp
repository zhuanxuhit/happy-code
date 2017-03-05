//
// Created by zhuanxu on 17/3/5.
//
#include <string>
#include <iostream>
#include <deque>
using namespace std;

// 例子：
// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
class Solution {
public:


    string removeKdigits(string num, int k) {
        // 思路我们要找到第一个递增序，非递减序
        deque<char> s;
        if(num.size() == 0){
            return "0";
        }
        int resultLen = num.size() - k;
        for(auto c:num){
            while (!s.empty() && s.back()>c && k > 0){
                k--;
                s.pop_back();
            }
            if(!s.empty() || c != '0') {
                s.push_back(c);
            }
        }
        // 接着我们要我们想要的个数
        string res;
        while (resultLen>0 && !s.empty()){
            res += s.front();
            s.pop_front();
            resultLen--;
        }
        if (res.size() == 0){
            res += '0';
        }
        return res;
    }

    string removeKdigits_v2(string num, int k){
        // 对上面的代码进行优化
        string res;
        int n=k,len = num.size(),cnt=0;
        for(auto c:num){
            while(!res.empty() && n>0 && res.back() > c){
                n--;
                res.pop_back();
            }
            res.push_back(c);
        }
        while (res[cnt] == '0') cnt++;
        res = res.substr(cnt,len-k-cnt);
        return !res.size() ? "0" : res;
    }
};

int main() {
    Solution s;
    cout << s.removeKdigits_v2("1432219", 3) << endl; // 1219
    cout << s.removeKdigits_v2("10200", 1) << endl; // 200
    cout << s.removeKdigits_v2("10", 2) << endl; //0
    cout << s.removeKdigits_v2("112", 1) << endl; // 11
    cout << s.removeKdigits_v2("222", 2) << endl; // 2
    cout << s.removeKdigits_v2("1234567890", 9) << endl; // 0
    cout << s.removeKdigits_v2("9", 1) << endl; // 0
}