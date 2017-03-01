//
// Created by zhuanxu on 17/2/28.
//
#include <string>
#include <iostream>
#include <vector>
#include <queue>
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

    string frequencySort_v2(string s) {
        // 思路：
        // 1. 构建一个优先队列（最大堆）
        // 2. 按字符排序
        // 3. 将相同字符串入堆，堆按字符串个数排序
        sort(s.begin(),s.end());
        auto cmp = [](string &a,string &b){ return a.size() < b.size();};
        priority_queue<string,vector<string>, decltype(cmp)> q(cmp);
        int i = 0;
        while(i<s.size()){
            int j =i + 1;
            while (j < s.size() && s[i] == s[j]){j++;}
            q.push(s.substr(i,j-i));
            i = j;
        }
        string ans;
        while (!q.empty()){
            ans += q.top();
            q.pop();
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.frequencySort_v1("tree") << endl;
    cout << s.frequencySort_v2("tree") << endl;
}
