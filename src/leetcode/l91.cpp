//
// Created by zhuanxu on 17/2/24.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // 给予数字字符串，返回个数
    // case "0" => 0
    // case "00" => 0
    // case "10" => 1
    // case "01" => 0
    // case "230" => 0
    // 放弃了。这个版本
    int numDecodings(string s) {
        // 递归, 注意 0，10，20
        if (s.size() == 0) {
            return 0;
        }
        if (s[0] == '0') {
            return 0;
        }
        if (s.size() == 1) {
            return 1;
        }
        int num = std::stoi(s.substr(0, 2));
        if (s.size() == 2) {
            if (num <= 26) {
                if (s[1] == '0') {
                    return 1;
                } else {
                    return 2;
                }
            }
            return 1;
        }
        // size >=3
        if (num <= 26) {
            if (num == 10 || num == 20) {
                return numDecodings(s.substr(2));
            } else {
                return numDecodings(s.substr(1)) + numDecodings(s.substr(2));
            }
        } else {
            if (s['1'] == '0') {
                return 0;
            }
            return numDecodings(s.substr(1));
        }
    }

    // 用dp， 从后向前看，可知道当前数字的后一个数。
    // 当前字符为0，不可解析， 则dp[i] = 0;
    // 当前字符可解析，那么dp[i] = dp[i+1], 当前字符加后面字符可以解析，
    // 那么 dp[i] = dp[i+1]+dp[i+2]
    int numDecodings_v2(string s) {
        int length = s.size();
        if (length == 0) {
            return 0;
        }
        int dp[length];
        dp[length] = 1;
        if (s[length - 1] == '0') {
            dp[length - 1] = 0;
        } else {
            dp[length - 1] = 1;
        }

        for (int i = length - 2; i >= 0; i--) {
            char cur = s[i];
            char next = s[i + 1];
            int num = (cur - '0') * 10 + next - '0';
            if (cur == '0') {
                dp[i] = 0;
            } else if (num <= 26) {
                dp[i] = dp[i + 1] + dp[i + 2];
            } else {
                dp[i] = dp[i + 1];
            }
        }
        return dp[0];
    }

    int dfs(string s, int pos, int *cache) {
        if (s[pos] == '0'){
            return 0;
        }
        if (pos == s.length()){
            return 1;
        }

        if (cache[pos] != -1) {
            return cache[pos];
        }

        int res = dfs(s,pos+1,cache);
        int num = (s[pos] - '0') * 10 + s[pos+1] - '0';
        if (pos + 1 < s.length()  && (s[pos] - '0') * 10 + s[pos+1] - '0' <= 26){
            res += dfs(s,pos+2,cache);
        }
        cache[res] = res;
        return res;
    }

    int numDecodings_v3(string s) {
        // 1. 定义状态
        // 2. 决策
        // 3. 初始状态和结束状态
        if (s.length() == 0 || s[0] == '0') {
            return 0;
        }
        int length = s.length();
        int cache[length];
        for (int i=0;i<length;i++){
            cache[i] = -1;
        }
        return dfs(s, 0, cache);
    }

    int numDecodings_v4(string s){
        // 定义状态为 已经解码的字符串个数
        if (s.length() == 0 || s[0] == '0') {
            return 0;
        }
        // 求123，则可以由 1 => 123 , 12 => 123 即两个状态转换过来
        // f[i] = f[i-1] + f[i-2]
        // f    = f1 + f2
        // 轮换  f2=f1,f1=f
        int f1,f2;
        f2=1;
        f1=1;
        for (int i=1;i<s.length();i++){
            int f = 0;
            if (s[i] != '0') {
                f += f1;
            }
            int num = (s[i-1]-'0') * 10 + s[i] - '0';
            if (num >= 10 && num <= 26){
                f += f2;
            }
            f2 = f1;
            f1 = f;
        }
        return f1;
    }
};


int main() {
    Solution s;
//    cout << string("1").substr(1) << endl;
//    cout << string("1").substr(0, 2) << endl;
//    cout << string("1").substr(2) << endl;
    cout << s.numDecodings_v4("12") << endl;
    cout << s.numDecodings_v4("") << endl;
    cout << s.numDecodings_v4("0") << endl;
    cout << s.numDecodings_v4("00") << endl;
    cout << s.numDecodings_v4("10") << endl;
    cout << s.numDecodings_v4("230") << endl;
}
