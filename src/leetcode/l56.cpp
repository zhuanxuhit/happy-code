#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

//Given [1,3],[2,6],[8,10],[15,18],
//return [1,6],[8,10],[15,18].
class Solution {
public:
    // [[1,4],[2,3]]
    vector<Interval> merge(vector<Interval> &intervals) {
        // 根据start 排序
        sort(intervals.begin(),intervals.end(),[](Interval a, Interval b){
            return a.start < b.start;
        });
        vector<Interval> ans;
        int end = INT_MIN;
        int start = INT_MIN;
        for (auto i : intervals){
            if (i.start <= end){
                end = max(end,i.end);
            }else {
                if ( end == INT_MIN){
                    start = i.start;
                    end = i.end;
                }else {
                    ans.push_back(Interval(start,end));
                    start = i.start;
                    end = i.end;
                }
            }
        }
        if (end != INT_MIN) {
            ans.push_back(Interval(start,end));
        }
        return ans;
    }
};

int main() {
    Solution s;
}
