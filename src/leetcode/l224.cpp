#include <string>
#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

//case :
//"1 + 1" = 2
//" 2-1 + 2 " = 3
//"(1+(4+5+2)-3)+(6+8)" = 23 可以将（）都去掉
// 1 - (2+1) = -2 不能()去掉 => 1 - 2 -1
class Solution {
public:
    int calculate(string s) {
        istringstream iss('+' + s);
//        string op="";
        char op;
        int n;
        int res = 0;
        bool prevPos = true;
        stack<int> st;
        while(iss >> op){
            if(op == '+' || op == '-') {
                if (iss >> n){
                    if (op == '-') n =-n;
                    res +=n;
                }else {
                    iss.clear();
                    char par;
                    iss >> par;
                    // 目前的问题是：当输入(的时候，需要状态重新保存
                    if (par == '('){
                        st.push(res);
                        st.push(op == '-' ? -1 : 1);
                        res = 0;
                    }else {
                        cerr << "can't resolve " << par << endl;
                        exit(-1);
                    }
                    iss >> n;
                    res +=n;
                }
            }else if (op == ')'){
                int sign = st.top(); st.pop();
                int pre = st.top();st.pop();
                res = pre + sign * res;
            }
        }
        return res;
    }
    int calculate_v2(string s) {
        stack <int> nums, ops;
        int num = 0;
        int rst = 0;
        int sign = 1;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            }
            else {
                rst += sign * num;
                num = 0;
                if (c == '+') sign = 1;
                if (c == '-') sign = -1;
                if (c == '(') {
                    nums.push(rst);
                    ops.push(sign);
                    rst = 0;
                    sign = 1;
                }
                if (c == ')' && ops.size()) {
                    rst = ops.top() * rst + nums.top();
                    ops.pop(); nums.pop();
                }
            }
        }
        rst += sign * num;
        return rst;
    }
};

int main() {
    Solution s;
    cout << s.calculate("1+1") << endl; // 2
    cout << s.calculate("2-1 + 2") << endl; // 2
    cout << s.calculate("(1+(4+5+2)-3)+(6+8)") << endl; // 23
    cout << s.calculate("1-(2+3) + (1-(2+4)-(1-2)+(1+(1+2)))") << endl; // -4
    cout << s.calculate("(5-(1+(5)))") << endl; // -1
}