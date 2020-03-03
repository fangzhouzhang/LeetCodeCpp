//
// Created by Fangzhou Zhang on 2020/3/3.
//
class Solution {
private:
    int dfs(TreeNode *root, int *m) {
        if (root == NULL) {
            return 0;
        }

        int left = dfs(root->left, m);
        left = max(left, 0);
        int right = dfs(root->right, m);
        right = max(right, 0);
        *m = max(*m, left + right + root->val);
        return left > right ? left + root->val : right + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int max = INT_MIN;
        dfs(root, &max);
        return max;
    }

};
