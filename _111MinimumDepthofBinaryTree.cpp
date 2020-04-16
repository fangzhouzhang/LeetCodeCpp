//
// Created by Fangzhou Zhang on 2020/4/16.
//
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (NULL == root) return 0;
        queue<TreeNode*> q;
        int res = 1;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *cur = q.front();
                q.pop();
                bool leaf = true;
                if (cur->left) {
                    q.push(cur->left);
                    leaf = false;
                }
                if (cur->right) {
                    q.push(cur->right);
                    leaf = false;
                }
                if (leaf) return res;
            }
            res++;
        }
        return res;
    }
};
