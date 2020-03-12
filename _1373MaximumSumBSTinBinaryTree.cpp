//
// Created by Fangzhou Zhang on 2020/3/12.
//

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        if (root == NULL) return 0;
        int res = 0;
        dfs(root, &res);
        return res;
    }

    vector<int> dfs(TreeNode* root, int *res) {
        if (root == NULL) return {0, INT_MAX, INT_MIN};
        vector<int> left = dfs(root->left, res);
        int l = left[0] == INT_MIN ? 0 : left[0];
        vector<int> right = dfs(root->right, res);
        int r = right[0] == INT_MIN ? 0 : right[0];
        if (left[0] != INT_MIN && right[0] != INT_MIN && root->val > left[2] && root->val < right[1]) {
            *res = max(*res, l + r + root->val);
            return {l + r + root->val, min(left[1], root->val), max(right[2], root->val)};
        }
        return {INT_MIN, min(left[1], root->val), max(right[2], root->val)};
    }

};