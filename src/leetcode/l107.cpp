#include <iostream>
#include <string>
#include <vector>

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

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
//    Given binary tree [3,9,20,null,null,15,7],
//    3
//    / \
//  9  20
//    /  \
//   15   7
// 输出
//    [
//    [15,7],
//    [9,20],
//    [3]
//    ]
    void pushLevel(int level, TreeNode *root,vector<vector<int>> &ans){
        if (root != nullptr){
            if (level >= ans.size()){
                ans.push_back({root->val});
            }else {
                ans[level].push_back(root->val);
            }
            pushLevel(level+1,root->left,ans);
            pushLevel(level+1,root->right,ans);
        }
    }

    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> ans;
        pushLevel(0,root,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main() {
    Solution s;
}
