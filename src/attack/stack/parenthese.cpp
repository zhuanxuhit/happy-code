//
// Created by zhuanxu on 2018/1/28.
//
#include <stack>
#include <iostream>

bool isLeftParenthese(char c){
    return c == '(' || c == '[' || c == '{';
}

bool isMatch(char left, char right){
    return  (left=='(' && right==')') || (left=='[' && right==']') || (left=='{' && right=='}');
}

bool MatchParenteses(const char* p) {
    std::stack<char> s;
    while (*p){
        if (isLeftParenthese(*p)){
            s.push(*p);
        }else {
            if (s.empty() || !isMatch(s.top(),*p)){
                return false;
            }
            s.pop();
        }
        p++;
    }
    return s.empty();
}

int main() {
    char* p = "(({})[])[()]";
    std::cout << MatchParenteses(p) << std::endl;
}