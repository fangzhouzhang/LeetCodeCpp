//
// Created by Fangzhou Zhang on 2020/4/22.
//
class Solution {
public:
    void flatten(TreeNode* root) {
        if (NULL == root) return;
        dfs(root);
    }

    TreeNode* dfs(TreeNode *root) {
        if (NULL == root) return NULL;
        TreeNode *zh = dfs(root->left);
        TreeNode *yh = dfs(root->right);

        if (NULL != zh && NULL != yh) {
            TreeNode *xy = root->left;
            TreeNode *tmp = root->right;

            root->left = NULL;
            root->right = xy;
            zh->right = tmp;

            return yh;
        } else if (NULL == zh && NULL != yh) {
            return yh;
        } else if (NULL != zh && NULL == yh) {
            TreeNode *xy = root->left;
            root->left = NULL;
            root->right = xy;
            return zh;
        } else {
            return root;
        }
    }

};
