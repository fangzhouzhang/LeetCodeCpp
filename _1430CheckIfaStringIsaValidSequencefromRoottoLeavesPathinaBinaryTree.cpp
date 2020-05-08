//
// Created by Fangzhou Zhang on 2020/5/7.
//
class Solution {
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if (NULL == root && arr.size() == 0) return true;
        if (NULL == root || arr.size() == 0) return false;
        return dfs(root, arr, 0);
    }

    bool dfs(TreeNode* root, vector<int>& arr, int idx) {
        if (idx == arr.size() - 1) {
            if (root == NULL) return false;
            if (root->val != arr[idx]) return false;
            if (root->left != NULL || root->right != NULL) return false;
            return true;
        } else {
            if (root == NULL) return false;
            if (root->val != arr[idx]) return false;
            return dfs(root->left, arr, idx + 1) || dfs(root->right, arr, idx + 1);
        }
    }
};
