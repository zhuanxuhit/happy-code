#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
//    "()())()" -> ["()()()", "(())()"]
//    "(a)())()" -> ["(a)()()", "(a())()"]
//    ")(" -> [""]
//    这道题让我们移除最少的括号使得给定字符串为一个合法的含有括号的字符串，
// 我们从小数学里就有括号，所以应该对合法的含有括号的字符串并不陌生，
// 字符串中的左右括号数应该相同，而且每个右括号左边一定有其对应的左括号，
// 而且题目中给的例子也说明了去除方法不唯一，我们需要找出所有合法的取法。
// 参考了网上大神的解法，这道题首先可以用 BFS 来解，我们先把给定字符串排入队中，
// 然后取出检测其是否合法，若合法直接返回，不合法的话，我们对其进行遍历，
// 对于遇到的左右括号的字符，我们去掉括号字符生成一个新的字符串，
// 如果这个字符串之前没有遇到过，将其排入队中，
// 我们用哈希表记录一个字符串是否出现过。我们对队列中的每个元素都进行相同的操作，
// 直到队列为空还没找到合法的字符串的话，那就返回空集，参见代码如下：
// 暴力解法：直接就是遍历所有可能。
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_map<string, int> visited;
        queue<string> q;
        q.push(s);
        ++visited[s];
        bool found = false;
        while (!q.empty()) {
            s = q.front(); q.pop();
            if (isValid(s)) {
                res.push_back(s);
                found = true;
            }
            if (found) continue;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] != '(' && s[i] != ')') continue;
                string t = s.substr(0, i) + s.substr(i + 1);
                if (visited.find(t) == visited.end()) {
                    q.push(t);
                    ++visited[t];
                }
            }
        }
        return res;
    }
    bool isValid(string t) {
        int cnt = 0;
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] == '(') ++cnt;
            if (t[i] == ')' && cnt-- == 0) return false;
        }
        return cnt == 0;
    }
};

int main () {
    Solution s;
}
