//
// Created by zhuanxu on 17/3/7.
//
#include <iostream>

using namespace std;


// 2, 3, 5 ，分解后只包含上面的
// 1 被认为是 ugly
class Solution {
public:
    bool isUgly(int num) {

        while(num >= 2 && num % 2 == 0){
            num = num / 2;
        }
        while(num >= 3 && num % 3 == 0){
            num = num / 3;
        }
        while(num >=5 && num % 5 == 0){
            num = num / 5;
        }
        return num == 1;
    }
};

int  main() {
    Solution s;
    cout << s.isUgly(1) << endl;
    cout << s.isUgly(6) << endl;
    cout << s.isUgly(8) << endl;

}