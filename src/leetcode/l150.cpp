//
// Created by zhuanxu on 17/3/2.
//
#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
// ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
class Solution {
public:
    bool isOperator(string s) {
        return s == "+" || s == "-" || s == "/" || s == "*";
    }
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


    int evalRPN(vector<string>& tokens) {
        stack<int> stokens;
        for(int i=0;i<tokens.size();i++){
            if (isOperator(tokens[i])){
                int right = stokens.top();
                stokens.pop();
                int left = stokens.top();
                stokens.pop();
                int value = do_op(left,right,tokens[i]);
                stokens.push(value);
            }else {
                stokens.push(std::stoi(tokens[i]));
            }
        }
        return stokens.top();
    }
};
int main() {
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    Solution s;
    cout << (s.evalRPN(tokens1)  == 9) << endl;
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    cout << (s.evalRPN(tokens2) == 6) << endl;
}