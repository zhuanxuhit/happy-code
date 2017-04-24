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
    bool isSymmetric(TreeNode *root) {
        // 递归的思路
        if (!root){
            return true;
        }
        return bfs(root->left,root->right);
    }
    bool isNodeSame(TreeNode *l, TreeNode *r) {
        if (!l || !r){
            return false;
        }
        return l->val == r->val;
    }

    bool bfs(TreeNode *l, TreeNode *r){
        if ( !l && !r){
            return true;
        }
        if (!isNodeSame(l,r)){
            return false;
        }
        return bfs(l->left,r->right) && bfs(l->right, r->left);
    }
};

int main() {
    Solution s;
    cout << s.isSymmetric(new TreeNode(1, (new TreeNode(2)), (new TreeNode(2)))) << endl;
}
