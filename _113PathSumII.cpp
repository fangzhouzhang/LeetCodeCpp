//
// Created by Fangzhou Zhang on 2020/4/16.
//
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (NULL == root) return res;
        vector<int> tmp;
        dfs(res, tmp, sum, root);
        return res;
    }

    void dfs(vector<vector<int>> &res, vector<int> &tmp, int sum,TreeNode* root) {
        if (NULL == root) return;
        if (!root->left && !root->right && sum == root->val) {
            tmp.push_back(root->val);
            res.push_back(tmp);
            tmp.pop_back();
        } else {
            tmp.push_back(root->val);
            dfs(res, tmp, sum - root->val, root->left);
            dfs(res, tmp, sum - root->val, root->right);
            tmp.pop_back();
        }
    }
};
