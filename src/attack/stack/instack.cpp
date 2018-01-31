//
// Created by zhuanxu on 2018/1/28.
//
#include <vector>
#include <stack>
#include <cassert>

bool CheckMatchStack(const char *in, const char *out) {
    assert(strlen(in) == strlen(out));
    auto size = static_cast<int>(strlen(in));
    std::stack<char> s;
    int j = -1;
    for(int i=0;i<size;i++){
        if (s.empty() || s.top() != out[i]){
            j++;
            while (j<size && in[j]!=out[i]){
                s.push(in[j]);
                j++;
            }
        }else {//if (s.top() == out[i]){
            s.pop();
        }
    }
    return s.empty();
}

int main() {
    assert(CheckMatchStack("ABCDEFG", "BAEDFGC"));
    assert(!CheckMatchStack("ABCD", "BDAC"));
}
