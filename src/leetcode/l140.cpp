#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <map>

using namespace std;


// s = "catsanddog",
// dict = ["cat", "cats", "and", "sand", "dog"].
// A solution is ["cats and dog", "cat sand dog"].
class Solution {
public:
    string implode(const vector<std::string>& elems, char delim)
    {
        string s;
        for (std::vector<std::string>::const_iterator ii = elems.begin(); ii != elems.end(); ++ii)
        {
            s += (*ii);
            if ( ii + 1 != elems.end() ) {
                s += delim;
            }
        }
        return s;
    }

    void dfs(string s,int pos,vector<string> &ans, vector<string> &path, map<string,bool>& wordDict) {
        if (s.length() == pos){
            ans.push_back(implode(path,' '));
            return;
        }
//        auto part = cache_.find(s.substr(pos));
//        if ( part != cache_.end()){
//            // 已经缓存了答案了
//            auto rights = cache_[s.substr(pos)];
//            string left = implode(path,' ');
//            for(auto r : rights ){
//                ans.push_back(left + " " + r);
//            }
//            return;
//        }

        for(int i=pos;i<s.length();i++){
            string t = s.substr(pos,i-pos+1);
            if (wordDict.find(t) != wordDict.end()){
                path.push_back(t);
                dfs(s,i+1,ans,path,wordDict);
                path.pop_back();
            }
        }
        // 此处问题是：ans 还包含了之前的结果，那显然是不对的
//        cache_[s.substr(pos)] = ans;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // 思路
        vector<string> ans = {};
        vector<string> path = {};

        // catsanddog 中找到 cat 匹配了，那么下一步其实就是
        // cat + wordBreak("sanddog",wordDict)
        map<string,bool> wordMap;
        for(auto w : wordDict) {
            wordMap[w] = true;
        }
        dfs(s,0,ans,path,wordMap);
        return ans;
    }


    vector<string> dfs_v2(string s,map<string,bool>& wordDict,map<string,vector<string>> &cache) {
        if (cache.find(s)!=cache.end()){
            return cache[s];
        }
        if (s==""){
            return vector<string>(0," ");
        }
        vector<string> ans;
        for(int i=1;i<=s.size();i++){
            string left = s.substr(0,i);
            if (wordDict.find(left)!=wordDict.end()){
                auto rights = dfs_v2(s.substr(i),wordDict,cache);
                // 有可能rights是空，但是是因为没有答案的空
                // 做区分
                for (auto r : rights) {
                    if (r == " ") {
                        ans.push_back(left);
                    }else {
                        ans.push_back(left + " " + r);
                    }
                }

            }
        }
        cache[s] = ans;
        return ans;
    }



    // 版本1的问题是没有做记忆，所以此处我们加上cache_缓存结果
    vector<string> wordBreak_v2(string s, vector<string>& wordDict) {
        // 思路
        map<string,vector<string>> cache;
        // catsanddog 中找到 cat 匹配了，那么下一步其实就是
        // cat + wordBreak("sanddog",wordDict)
        map<string,bool> wordMap;
        for(auto w : wordDict) {
            wordMap[w] = true;
        }
        vector<string> ans = dfs_v2(s,wordMap,cache);
        return ans;
    }

private:

};

int main () {
    Solution s;
    string ss = "catsanddog";
    vector<string> dict = {"cat", "cats", "and", "sand", "dog"};
    auto res = s.wordBreak_v2(ss,dict);
    for(auto w : res) {
        cout << w << endl;
    }
    cout << endl;
}
