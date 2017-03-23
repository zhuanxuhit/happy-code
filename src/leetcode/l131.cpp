#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    // "aab" 输出所有的回文串方案
//    [
//    ["aa","b"],
//    ["a","a","b"]
//    ]
    // 思路：先找出里面最大的回文子串,然后对于剩余再做同样的操作
    // 那怎么找最大回文子串呢？

    bool is_palindrome(string s){
        for (int i=0,j= (int) (s.size() - 1); i < j; i++,j--) {
            if (s[i] != s[j]){
                return false;
            }
        }
        return true;
    }

    void backtrack(string s,int start,vector<vector<string>> &result, vector<string> &candidate){
        if (s.size() == start) {
            result.push_back(candidate);
            return;
        }
        for(int i=start+1;i<=s.size();i++){
            string a = s.substr(start,i-start);
            if (is_palindrome(a)) {
                candidate.push_back(a);
                backtrack(s,i,result,candidate);
                candidate.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        // 暴力方法，枚举所有，怎么个思路呢？
        vector<vector<string>> result;
        vector<string> candidate;
        backtrack(s,0,result,candidate);
        return result;
    }


    // 下面的思路是递归
    // 左边如果是回文 判断右边是否是
    vector<vector<string>> partition_v2(string s) {
        vector<vector<string>> result;
        // 递归
        if (s.size() == 0){
            return result;
        }

        if (is_palindrome(s)){
            result.push_back(vector<string>({s}));
        }
        // 再看能够细分了
        for(int i=1;i<=s.size();i++){
            string left = s.substr(0,i);
            if (is_palindrome(left)){
                vector<vector<string>> rights = partition_v2(s.substr(i));
                if (rights.size() > 0){
                    for(int j=0;j<rights.size();j++){
                        vector<string> right = rights[j];
                        vector<string> item;
                        item.push_back(left);
                        for (auto r : right){
                            item.push_back(r);
                        }
                        result.push_back(item);
                    }
                }
            }
        }
        return result;
    }

    // dp的思路

};

int main() {
    Solution s;
    vector<vector<string>> result = s.partition_v2("aab");

    s.is_palindrome("aa");

    for(auto i=result.begin();i!=result.end();i++){
        cout << "[";
        for(auto j=(*i).begin(); j!=(*i).end(); j++){
            cout << *j << ",";
        }
        cout << "]" << endl;
    }
}