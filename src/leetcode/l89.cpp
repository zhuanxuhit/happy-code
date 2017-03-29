#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 输入n = 2
// 返回 0,1,2,3 即 2^2的一个
// 有个变种，需要按顺序来
// 00
// 01
// 11
// 10
// 000
// 001
// 011
// 010
// 110
// 111
// 110
// 这个规则是每次只能有一位不同的。。
class Solution {
public:

    // 这就是一个格雷码
    vector<int> grayCode(int n) {
        vector<int> ans{0};
        for(int i=0;i<n;i++) {
            int end = ans.size() - 1;
            int r = pow(2,i);
            for(int j=end;j>=0;j--){
                ans.push_back(r+ans[j]);
            }
        }
        return ans;
    }

};

int main() {
    Solution s;
    vector<int> ans = s.grayCode(2);
    cout << "[";
    for_each(ans.begin(), ans.end(), [](int i) {
        cout << i << ",";
    });
    cout << "]" << endl;
}