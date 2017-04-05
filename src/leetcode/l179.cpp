#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:



    string largestNumber(vector<int>& nums) {
        // 对数进行排序，
        sort(nums.begin(),nums.end(),[](int a,int b){
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });
        string res;
        for (int n : nums){
            res += to_string(n);
        }
        return res[0] =='0' ? "0":res;
    }
};

int main () {
    Solution s;
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << s.largestNumber(nums) << endl;
}
