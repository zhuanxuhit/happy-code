//
// Created by zhuanxu on 2018/7/8.
//


#include <algorithm>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void midOrder(TreeNode *node, int &sum, int &max_sum) {
        if (!node) {
            return;
        }
        int leftSum = 0;
        int rightSum = 0;
        if (node->left) {
            midOrder(node->left, leftSum, max_sum);
        }
        if (node->right) {
            midOrder(node->right, rightSum, max_sum);
        }
        // sum表示已node为根节点的最大路径
        sum = std::max({node->val, leftSum + node->val, rightSum + node->val});
        max_sum = std::max({max_sum, sum, leftSum + node->val + rightSum});
    }

    int maxPathSum(TreeNode *root) {
//        Input: [-10,9,20,null,null,15,7]
//
//            -10
//            / \
//           9  20
//             /  \
//           15   7
//
//            Output: 42
        int max_sum = std::numeric_limits<int>::min();
        int sum = 0;
        midOrder(root, sum, max_sum);
        return max_sum;
    }
};

int main() {
    TreeNode root(-10);
    TreeNode a(9);
    TreeNode b(20);
    TreeNode c(15);
    TreeNode d(7);
    root.left = &a;
    root.right = &b;
    b.left = &c;
    b.right = &d;

    Solution solution;
    std::cout << solution.maxPathSum(&root);
}