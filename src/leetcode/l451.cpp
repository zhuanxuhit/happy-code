//
// Created by zhuanxu on 17/2/28.
//
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string frequencySort_v1(string s) {
        // 先排序，然后在输出
        unordered_map<char,int> frequency;
        vector<string> bucket(s.size()+1,"");
        string res;
        // 记录每个字符的频率
        for (char c:s) frequency[c]++;
        // 把字符放到bucket中，频率作为index
        for(auto it:frequency){
            char ch = it.first;
            int count = it.second;
            // 插入count个字符
            bucket[count].append(count,ch);
        }
        // 利用降序进行输出
        for (int i=s.size();i>0;i--){
            if (!bucket[i].empty()){
                res += bucket[i];
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.frequencySort_v1("tree") << endl;
}
