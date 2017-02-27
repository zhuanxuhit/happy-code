//
// Created by zhuanxu on 17/2/21.
//
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <deque>
#include <ctype.h>
#include <sstream>

using namespace std;

class Solution {

public:
    //Longest Substring Without Repeating Characters
    int lengthOfLongestSubstring_1(string s) {
        // 思路1：从前往后匹配
        int max_len = 0;
        for (int i = 0; i < s.size(); i++) {
            map<char, int> sets;
            for (int j=i;j<s.size();j++) {
                if (sets.find(s[j]) != sets.end()) {
                    break;
                } else {
                    sets[s[j]] = 1;
                }
            }
            max_len = max(max_len, (int)sets.size());
        }
        return max_len;
    }
    //	362 ms
    int lengthOfLongestSubstring_2(string s){
        // 思路2：只保留部分
        int j=0;
        map<char,int> sets;
        int max_len = 0;
        while(j<s.size()){
            if (sets.find(s[j])==sets.end()){
                sets[s[j]] = j;
            }else {
                max_len = max(max_len, (int)sets.size());
                // remove 【sets[s[j]] - j]的所有内容
                // 只保留
                int n = sets[s[j]];
                sets.clear();
                for (int k=n+1;k<=j;k++){
                    sets[s[k]] = k;
                }
            }
            j++;
        }
        max_len = max(max_len, (int)sets.size());
        return max_len;
    }

    int lengthOfLongestSubstring_3(string s){
        // 对于上面优化下，其实我只想知道 char 的位置，然后每次都只要更新最新的位置，而不是去重新入队
        vector<int> pos(256,0);
        int start = 1;
        int longest = 0;
        for (int idx=1;idx<=s.size();++idx){
            char current = s[idx-1];
            if (pos[current]>=start){
                start = pos[current] + 1;
            }else {
                longest = max(longest,idx - start + 1);
            }
            pos[current] = idx;
        }
        return longest;
    }

    int lengthOfLongestSubstring_4(string s) {
        // 不变量是什么
        // (start,i] 中的都是不重复的
        // 长度 = i - start
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for(int i=0;i<s.size();i++){
            if (dict[s[i]] > start) {
                start = dict[s[i]];
            }
            dict[s[i]] = i;
            maxLen = max(maxLen,i-start);
        }

        return maxLen;
    }

    int lengthOfLongestSubstring_5(string s) {
        // dp的思路
        // 不变量 L[i] = s[m,i]
        // 此处都是闭区间
        int longest = 0;
        int m = 0;
        vector<int> dict(256,-1);
        for (int i=0;i<s.size();i++){
            m = max(dict[s[i]]+1,m);
            dict[s[i]] = i;
            longest = max(longest,i-m+1);
        }
        return longest;
    }

    string longestCommonPrefix(vector<string>& strs) {

        string prefix = "";
        for(int idx=0; strs.size()>0; prefix+=strs[0][idx], idx++)
            for(int i=0; i<strs.size(); i++)
                if(idx >= strs[i].size() ||(i > 0 && strs[i][idx] != strs[i-1][idx]))
                    return prefix;
        return prefix;

//        if (strs.size() < 1){
//            return "";
//        }
//        string std = strs[0];
//        string prefix = "";
//        // 以std字符串为准，开始比较
//        for (int i=0; i<std.size();i++){
//            for(int j=1;j<strs.size();j++){
//                if (i > strs[j].size() - 1 || std[i] != strs[j][i]) {
//                    return prefix;
//                }
//            }
//            prefix += std[i];
//        }
//        return prefix;
    }

    //**********************************************************
    //************227. Basic Calculator II**********************
    //**********************************************************
    // "3+2*2" = 7
    // " 3/2 " = 1
    // " 3+5 / 2 " = 5
    int do_op(int left,int right,string op){
        if (op == "+"){
            return left+right;
        }else if(op== "-"){
            return left-right;
        }else if(op == "*"){
            return left * right;
        }else {
            return left / right;
        }
    }
    bool isOperator(char c){
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    int caculate_value(string s){
        string left;
        string right;
        string op;
        for (auto c : s){
            if (isdigit(c)){
                left += c;
            }else if (isOperator(c)){
                op = c;
                break;
            }
        }
        if (op == " "){
            return std::stoi( left );
        }
//        if (op == "*" || op == "/"){
//            // 先进行计算,有问题，重新整理思路
//        }

        // find right
        bool opfind = false;
        for (auto c : s){
            // 得到
            if (opfind){
                right += c;
            }else if (isOperator(c)){
                opfind = true;
            }
        }

        int leftv = caculate_value(left);
        int rightv = caculate_value(right);
        return do_op(leftv,rightv,op);
    }

    int leetcode_227_calculate_v1(string s) {
        // 要解析，并且还有注意结合律
        return caculate_value(s);
    }

    int leetcode_227_calculate_v2(string s) {
        // 如果遇到 + - 直接入队，如果遇到 * / 先计算后再入队
        deque<string> ops;
        string digits;
        for (int i=0;i<s.size();i++) {
            char c = s[i];
            if (isdigit(c)){
                digits += c;
            }else if (c == '+' || c == '-'){
                ops.push_back(digits);
                ops.push_back(string(1,c));
                digits = "";
            }else if(c == '*' || c == '/'){
                // 找到数字
                string right;
                for(i=i+1;i<s.size();i++){
                    if (isdigit(s[i])){
                        right += s[i];
                    }
                    else if (isOperator(s[i])){
                        break;
                    }
                }
                // 找到了right
                int value = do_op(std::stoi(digits),std::stoi(right),string(1,c));
                digits = std::to_string(value);
                i--;
            }
        }
        // 此时ops中只有 数字 和 "+" '-'操作
        string op;
        string right;
        ops.push_back(digits);

        int value = std::stoi(ops.front());
        ops.pop_front();
        while(!ops.empty()){
            op = ops.front();
            ops.pop_front();
            right = ops.front();
            ops.pop_front();
            value = do_op(value,std::stoi(right),op);
        }

        return value;
    }

    int leetcode_227_calculate_v3(string s){
        // 回退的思路
        int left = 0;
        int prev = 0;
        char lastSign = '+';
        string num;
        s += '+';
        for (auto c : s){
            if (isdigit(c)){
                num += c;
            }else if (c == '+' || c =='-' ){
                prev = do_op(prev,std::stoi(num),string(1,lastSign));
                lastSign = c;
                num = "";
            }else if (c =='/' || c =='*') {
                if (lastSign == '-' || lastSign == '+'){
                    left = left + prev;
                    prev = (lastSign == '-') ? -(std::stoi(num)) : std::stoi(num);
                }else {
                    prev = do_op(prev,std::stoi(num),string(1,lastSign));
                }
                lastSign = c;
                num = "";
            }
        }
        return prev + left;
    }

    int leetcode_227_calculate_v4(string s){
        // 回退的思路
        int left = 0;
        int prev = 0;
        char lastSign = '+';
        string num;
        s += '+';
        for (auto c : s){
            if (isdigit(c)){
                num += c;
            } else if (isOperator(c)) {
                if (lastSign == '-' || lastSign == '+'){
                    left = left + prev;
                    prev = (lastSign == '-') ? -(std::stoi(num)) : std::stoi(num);
                }else {
                    prev = do_op(prev,std::stoi(num),string(1,lastSign));
                }
                lastSign = c;
                num = "";
            }
        }
        return prev + left;
    }

    int leetcode_227_calculate_v5(string s){
        // 此处不变就是：res + cur (op?) 根据op来操作
        // 更牛逼的思路，流的做法
        istringstream iss('+'+s+'+');
        int res=0;
        int cur=0;
        char op;
        while(iss >> op) {
            // 遇到加和减
            if (op == '+' || op =='-'){
                res += cur;
                iss >> cur;
                if (op == '-') cur = -cur;
            }else if (op == '*' || op =='/'){
                int n;
                iss >> n;
                if (op =='*') cur *=n;
                else cur /=n;
            }
        }
        return res;
    }
};




int main() {
    Solution s;
    cout << "l3: " << s.lengthOfLongestSubstring_2("pwwkew")<<endl; // 3
    vector<string> strs = {"a","b"};
    cout << s.longestCommonPrefix(strs) << endl;


//    cout << s.leetcode_227_calculate_v1(" 3+5 / 2 ") << endl;
//    cout << s.leetcode_227_calculate_v2(" 3+5 / 2 ") << endl;
//    cout << s.leetcode_227_calculate_v1("100000000/1/2/3/4/5/6/7/8/9/10") << endl;
    cout << s.leetcode_227_calculate_v5("100000000/1/2/3/4/5/6/7/8/9/10") << endl;
    cout << s.leetcode_227_calculate_v5(" 1 - 1 + 1") << endl;
}