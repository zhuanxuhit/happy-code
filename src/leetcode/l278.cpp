#include <string>
#include <iostream>


using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // [1,2,3...n]
        int left = 0;
        int right = n-1;
        // [left,right]
        while (left <= right){
            int mid = left + (right-left)/2;
            if (isBadVersion(mid)){
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }
        // 终止条件肯定是 left > right
        return min(n-1,left);
    }
};

int main() {

}
