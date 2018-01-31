//
// Created by zhuanxu on 2018/1/28.
//

// (())() 求匹配的最大长度

#include <cstring>
#include <stack>
#include <cassert>

int FindLongest(const char* p){
    auto size = static_cast<int>(strlen(p));
    std::stack<int> s;
    int start = -1;
    int answer = 0;
    for (int i=0;i<size;i++){
        if (p[i] =='('){
            s.push(i);
        }else { // p[i] = ')'
            if (s.empty()){ // 说明没匹配上了。重新开始
//                answer = std::max(answer, i - start - 1);
                start = i; //
            }else {
                int top = s.top();
                s.pop();
                if (s.empty()){
                    answer = std::max(answer, i - start);
                }else {
                    answer = std::max(answer, i - top + 1);
                }
            }
        }
    }
    return answer;
}


int FindLongest2(const char* p) {
    auto size = static_cast<int>(strlen(p));
    std::stack<int> s;
    int start = -1;
    int answer = 0;
    int deep =0;
    // 第一步，从左往右匹配
    for (int i=0;i<size;i++){
        if (p[i] == '('){
            deep++;
        }else {
            deep--;
            if (deep == 0){
                // 完全匹配 "(()))"
                answer = std::max(answer, i - start);
            } else if (deep<0){
                start = i;
            }
        }
    }
    // 从右往左,解决 "(()()" 这种问题
    deep = 0;
    start = size;
    for (int i=size-1;i>=0;i--){
        if(p[i] == ')'){
            deep++;
        }else {
            deep--;
            if (deep == 0){
                answer = std::max(answer, start - i);
            } else if (deep < 0){
                // "(()"
                start = i;
            }
        }
    }
    return answer;
}

int main(){
    assert(FindLongest("(()")==2);
    assert(FindLongest("(())")==4);
    assert(FindLongest("()()")==4);
    assert(FindLongest("()(())")==6);
    assert(FindLongest("(()())")==6);
    assert(FindLongest("()(()))")==6);
    assert(FindLongest("(((()()))")==8);

    assert(FindLongest2("(()")==2);
    assert(FindLongest2("(())")==4);
    assert(FindLongest2("()()")==4);
    assert(FindLongest2("()(())")==6);
    assert(FindLongest2("(()())")==6);
    assert(FindLongest2("()(()))")==6);
    assert(FindLongest2("(((()()))")==8);
}