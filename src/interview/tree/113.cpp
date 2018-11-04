//
// Created by zhuanxu on 2018/7/7.
//

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    void traversal(TreeNode *root,
                   std::vector<int> &path,
                   std::vector <vector<int>> &result,
                   int path_sum,
                   int sum) {
        if (!root){
            return;
        }

        path_sum += root->val;
        path.push_back(root->val);
        if (root->left == nullptr and
            root->right == nullptr and
            path_sum == sum  ) {
            result.push_back(path);
        }
        traversal(root->left,path,result,path_sum,sum);
        traversal(root->right,path,result,path_sum,sum);
        path.pop_back();
    }

    vector <vector<int>> pathSum(TreeNode *root, int sum) {
        std::vector <vector<int>> result;
        vector<int> path;
        traversal(root,path,result,0,sum);
        return result;
    }
};