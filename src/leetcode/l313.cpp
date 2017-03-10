//
// Created by zhuanxu on 17/3/9.
//
#include <iostream>
#include <vector>

using namespace std;

// 找到第 n 个ugly number
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> pos(primes.size(),0);
        vector<int> uglys(1,1);
        while(--n>0){
            int mn = INT_MAX;
            for(int i=0;i<primes.size();i++) mn = min(mn,uglys[pos[i]]*primes[i]);
            for(int i=0;i<primes.size();i++) if (mn == uglys[pos[i]]*primes[i]) pos[i]++;
            uglys.push_back(mn);
        }
        return uglys.back();
    }
};
int main() {
    Solution s;
    vector<int> primes = {2,3,5};
    cout << s.nthSuperUglyNumber(10,primes) << endl;
    cout << s.nthSuperUglyNumber(1,primes) << endl;
    cout << s.nthSuperUglyNumber(7,primes) << endl;
}
