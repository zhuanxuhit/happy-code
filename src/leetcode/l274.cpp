#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // case: citations = [3, 0, 6, 1, 5] => 0,1,3,5,6
    // h = 3
    // A scientist has index h if h of his/her N papers have at least h citations each,
    // and the other N − h papers have no more than h citations each.
    int hIndex(vector<int>& citations) {
        // 对 citations 排个序
        vector<int> cits = citations;
        sort(cits.begin(),cits.end());
        // 此处假设 h , 则至少有  h篇文档其引用数要大于 h
        int l = 1, r = cits.size();
        // [l,r]
        while (l<=r){
            int m = l+(r-l)/2;
            // 至少有m篇文档要大于m
            int index = cits.size() - m;
            if (cits[index] >= m){
                l = m + 1;
            }else {
                r = m - 1;
            }
        }
        // 结束条件  r = l - 1
        return r;
    }
};

int main () {
    Solution s;
//    vector<int> citations = {3, 0, 6, 1, 5};
//    vector<int> citations = {100};
    vector<int> citations = {0,1};

    cout << s.hIndex(citations);
}
