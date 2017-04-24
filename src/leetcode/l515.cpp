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
    vector<int> largestValues(TreeNode* root) {
        // 找到每一行的最大值
//        bfs
        vector<int> ans;
        if (root == nullptr){
            return ans;
        }
        deque<TreeNode*> nodes;
        nodes.push_back(root);
        bfs(ans,nodes);
        return ans;
    }
    void bfs(vector<int> &ans, deque<TreeNode*> &nodes){
        int ls = nodes.size();
        int lmax = INT_MIN;
        while (ls>0){
            TreeNode*node = nodes.front();
            nodes.pop_front();
            ls--;
            if (node){
                lmax = max(node->val,lmax);
                if (node->left) nodes.push_back(node->left);
                if (node->right) nodes.push_back(node->right);
            }
            if (ls==0){
                ans.push_back(lmax);
            }
        }
        if (nodes.size()>0){
            bfs(ans,nodes);
        }
    }
};

int main () {
    Solution s;
}
