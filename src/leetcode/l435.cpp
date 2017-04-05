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

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval> &intervals) {
        sort(intervals.begin(),intervals.end(),[](Interval &a, Interval &b){
            return a.start < b.start;
        });
        int ans = 0;
        if (intervals.size() <= 0) {
            return ans;
        }

        // 此处还有负数
        ans = -1; // 为了第一个
        int end = intervals[0].end;
        for(auto interval : intervals) {
            if (interval.start < end){
                ans++;
                // 此处要判断是否更新,选择一个更短的end，移除大的end
                if (interval.end < end){
                    end = interval.end;
                }
            }else {
                end = interval.end;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
}
