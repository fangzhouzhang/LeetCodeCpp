//
// Created by Fangzhou Zhang on 2020/4/16.
//
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (NULL == root) return false;
        queue<TreeNode*> q;
        q.push(root);
        root->val = sum - root->val;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *cur = q.front();
                q.pop();
                if (cur->left == NULL && cur->right == NULL) {
                    if (cur->val == 0) return true;
                }
                if (cur->left != NULL) {
                    q.push(cur->left);
                    cur->left->val = cur->val - cur->left->val;
                }
                if (cur->right != NULL) {
                    q.push(cur->right);
                    cur->right->val = cur->val - cur->right->val;
                }
            }
        }
        return false;
    }
};
