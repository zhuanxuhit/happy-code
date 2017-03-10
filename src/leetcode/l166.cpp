#include <iostream>
#include <set>
#include <queue>

using namespace std;

//Given numerator = 1, denominator = 2, return "0.5".
//Given numerator = 2, denominator = 1, return "2".
//Given numerator = 2, denominator = 3, return "0.(6)".
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // 如果能整除我们挺好做的
        int prev = numerator / denominator;
        int remainder = numerator % denominator;
        string res;
        res += to_string(prev);
        if (remainder == 0){
            return res;
        }else {
            res += ".";
        }
        prev = 0;
        // 目前只处理了一位的重复，但是如果多位呢？
        while(remainder != 0){
            remainder *= 10;
            int result = remainder / denominator;
            if (result == 0 || result != prev){
                res += to_string(result);
                remainder = remainder % denominator;
                prev = result;
            }else {
                res = res.substr(0,res.length()-1);
                res += "(";
                res += to_string(result);
                res += ")";
                break;
            }
        }
        return res;
    }

    string fractionToDecimal_v2(int numerator, int denominator){
        // v1的问题是不好处理1,99的case,我们需要重新想一个算法
        // 我们基于一个观察，我们出现循环的时候，我们会重复出现 1 / 99 这个算式
        // 因此我们希望得到的是 1 即被除数是否已经出现过了，如果已经出现过，则进入循环了。
        // 先求整数部分
        // 此处一定要够大，如果声明 int 就会出错了
        long long n = numerator;
        long long d = denominator;
        // 还要考虑负数
        set<int> nums;
        queue<pair<int,int>> q;
        string res;
        if ((n>0 && d<0) || (n<0 && d >0)){
            res += '-';
        }
        n = abs(n);
        d = abs(d);
        res += to_string(n/d);

        while((n = (n % d)*10 ) != 0 && nums.count(n) == 0){
            // 余数不为0，并未也没有重复出现计算范式
            nums.insert(n);
            q.push({n,n/d});
        }
        if (q.size() != 0){
            res += '.';
        }
        while(q.size()){
            if (q.front().first == n){
                // 出现重复了
                res += '(';
            }
            res += to_string(q.front().second);
            q.pop();
        }
        if (n) res += ')';

        return res;
    }
};

int main() {
    Solution s;
    cout << s.fractionToDecimal_v2(1,2)<< endl;
    cout << s.fractionToDecimal_v2(2,3)<< endl;
    cout << s.fractionToDecimal_v2(1,90)<< endl;
    cout << s.fractionToDecimal_v2(1,99)<< endl;
    cout << s.fractionToDecimal_v2(-1,-2147483648)<< endl;
}