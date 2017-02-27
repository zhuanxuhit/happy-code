//
// Created by zhuanxu on 17/2/23.
//
//434. Number of Segments in a String
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int cnt = 0;
        bool skip = true;
        s += ' ';
        for (auto c : s){
            if (skip && c == ' '){
                continue;
            }else if (c != ' '){
                skip = false;
            }else if(c == ' ' && !skip){
                cnt++;
                skip = true;
            }
        }
        return cnt;
    }
    int countSegments2(string s) {
        int res=0;
        s+=' ';
        for(int i=1;i<s.size();i++) {
            if (s[i] ==' ' && s[i-1] != ' ') res++;
        }
        return res;
    }
};
int main() {
    Solution s;
    cout << s.countSegments("Hello, my name is John") << endl;
    cout << s.countSegments2("Hello, my name is John") << endl;
}