//
// Created by Fangzhou Zhang on 2020/4/8.
//
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }

    bool dfs(TreeNode *root, long low, long up) {
        if (root == NULL) return true;
        if (root->val <= low || root->val >= up) return false;
        return dfs(root->left, low, root->val) && dfs(root->right, root->val, up);
    }
};
