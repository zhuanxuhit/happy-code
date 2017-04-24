#include <iostream>
#include <string>
#include <vector>

using namespace std;


// case 1
//Input:
//        s = "abpcplea", d = ["ale","apple","monkey","plea"]
//
//Output:
//"apple"
// case 2
//Input:
//        s = "abpcplea", d = ["a","b","c"]
//
//Output:
//"a"
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        // 思路
        // 我们要找出最长的，如果长度相同，按字典序
        // 那其实就是我们先对 d 进行排序，排序规则是长度和字典序
        sort(d.begin(), d.end(), [](string a, string b){
            if (a.length() == b.length()){
                return  a > b; // 按字典降序
            }else {
                return (a.length() < b.length());
            }
        });
        // 现在d是有序的了，下一步就是匹配了，可以采用二分查找的思路
        // 不过找的是最后一个满足条件的数，这个二分有问题，如果不二分，直接从后往前找呢？
        // 所有就变为直接从后往前找了



        // 左闭右开
//        int l = 0, r = d.size();
        auto match = [](string a, string b) {
            int m = a.size(),n = b.size();
            int i=0,j=0;
            while(i<m && j <n){
                if (a[i] == b[j]){
                    i++;
                    j++;
                }else {
                    i++;
                }
            }
            return j==n;
        };

        for (int i=d.size()-1;i>=0;i--){
            if (match(s,d[i])){
                return d[i];
            }
        }
        return "";
//        while(l < r){
//            int m = l + (r-l)/2;
//            if (match(s, d[m])){
//                // 继续往右找
//                l = m+1;
//            }else {
//                // 关键是如果不同，你是往左还是往右呢？
//
//            }
//        }
    }
};
template <typename T>
void print_vector(vector<T> v){
    int n = v.size();
    if (n <=0 ){
        return;
    }
    cout << "[";
    for (int i=0;i<v.size();i++){
        cout << v[i];
        if (i!=n-1){
            cout << ",";
        }
    };
    cout << "]" << endl;
};

int main () {
    Solution s;
    vector<string> d = {"ale","apple","monkey","plea"};
//    vector<string> d = {"a","b","c"};
    cout << s.findLongestWord("abpcplea",d);
}
