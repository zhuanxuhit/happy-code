#include <string>
#include <iostream>
#include <cmath>

using namespace std;

// For an integer n, we call k>=2 a good base of n, if all digits of n base k are 1.
// case：
//Input: "4681"
//Output: "8"
//Explanation: 4681 base 8 is 11111.

class Solution {
public:
//    Note:
//    1. The range of n is [3, 10^18].
//    2. The string representing n is always valid and will not have leading zeros.
    string smallestGoodBase(string n) {
        // n 的范围是 [3, 10^18]
        // 而最小基是2 n = 1 + k^1 + k^2 + .... + k^m
        // n = 1 * (1 - k^(m+1)) /  (1-k)
        // 如果此处k=2，则 n = 2^(m+1) - 1
        // m = log2(n+1)-1 这是最大
        // 因此 m = [1,max_m]
        // 我们知道了 k = [1,n-1],我们也知道了m，那我们就可以计算出最终的值了
        // 我们的目的是求出最小的k，因此我们希望m是尽可能的大的，所以我们将m从大到小
        // 我们固定住 m，来求k，如果 sum < n，则放大k，如果 sum > n 则减小k
        unsigned long long intn = (unsigned long long) stoll(n);
        int maxm = static_cast<int>(log2(intn + 1) - 1);
        for(int m=maxm;m>=1;m--){
            unsigned long long k = match(intn,m);
            if (k != 0) return to_string(k);
        }
        return to_string(intn - 1);
    }
    unsigned long long match(unsigned long long n,int m){
        // 我们要怎么定义边界 [1,right] // right 最大是多少呢？
        // n = 1 + k^1 + k^2 + .... + k^m
        // n > k^m => k < n ^ (1/m)
        // n < (k+1)^m =>  k > n^(1/m) - 1
        // 于是我们就有了k的最大边界
        unsigned long long right = (unsigned long long) pow(n, 1.0 / m);
        unsigned long long left = 1;
        while (left<=right){
            unsigned long long k = (right-left)/2 + left;
            unsigned long long sum = 1,cur=1;
            for (int i=1;i<=m;i++){
                cur *= k;
                sum += cur;
            }
//            unsigned long long sum = (unsigned long long int) ((1 - pow(k, m + 1)) / (1 - k));
            if (sum == n) return k;
            if (sum > n) right = k - 1;
            else left = k + 1;
        }
        return 0;
    }
};


int main() {
    Solution s;
    cout << s.smallestGoodBase("13") << endl;
    cout << s.smallestGoodBase("4681") << endl;
    cout << s.smallestGoodBase("1000000000000000000") << endl;
}