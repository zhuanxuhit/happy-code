#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x,TreeNode *left=NULL, TreeNode *right=NULL) : val(x), left(left), right(right) {}
};
class Solution {
public:
//    Input:
//
//    1
//    / \
//      2   3
//    /   / \
//    4   5   6
//    /
//    7
//
//    Output:
//    7
    int findBottomLeftValue(TreeNode* root) {
        deque<TreeNode*> bfs;
        bfs.push_back(root);
        for(;;){
//            if (bfs.size() == 1 && bfs.front()->left == nullptr && bfs.front()->right == nullptr){
//                return bfs.front()->val;
//            }
            int l = bfs.size();
            auto left = bfs.front();
//            bool ans = true;
            while (l>0){
                if (bfs.front()->left){
                    bfs.push_back(bfs.front()->left);
                }
                if (bfs.front()->right){
                    bfs.push_back(bfs.front()->right);
                }
                bfs.pop_front();
                l--;
            }
            if (bfs.size() == 0){
                return left->val;
            }
        }
    }
};

int main () {
    Solution s;
    cout << s.findBottomLeftValue(new TreeNode(1, (new TreeNode(1)), (new TreeNode(2)))) << endl;
}
