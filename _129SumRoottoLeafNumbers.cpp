//
// Created by Fangzhou Zhang on 2020/4/27.
//
class Solution {
public:
    int res = 0;
    int sumNumbers(TreeNode* root) {
        if (NULL == root) return 0;

        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode *root, int cur) {
        cur = cur * 10 + root->val;
        if (NULL == root->left && NULL == root->right) {
            res = res +cur;
            return;
        }

        if (NULL != root->left) {
            dfs(root->left, cur);
        }
        if (NULL != root->right) {
            dfs(root->right, cur);
        }
    }
};
