//
// Created by zhuanxu on 17/3/6.
//



#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // case 19
    bool isHappy(int n) {
        unordered_map<int,bool> result;
        while(result.find(n)== (result.end())) {
            result[n] = true;
            int num = n;
            n = 0;
            while (num != 0){
                n += (num % 10)*(num % 10);
                num = num / 10;
            }
            if (n == 1) {
                return true;
            }
        }
        return false;
    }
};
int main () {
    Solution s;
    cout << s.isHappy(19) << endl;
}