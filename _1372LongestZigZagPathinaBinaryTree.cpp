//
// Created by Fangzhou Zhang on 2020/3/12.
//
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        int res = 0;
        dfs(root, &res);
        return res;
    }

    vector<int> dfs(TreeNode* root, int *res) {
        if (root == NULL) return {-1, -1};
        vector<int> left = dfs(root->left, res);
        vector<int> right = dfs(root->right, res);
        *res = max(*res, max(left[1] + 1, right[0] + 1));
        return {left[1] + 1, right[0] + 1};
    }
};
