//
// Created by Fangzhou Zhang on 2020/4/12.
//
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        stack<vector<int>> stack;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> tmp;
            for (int i = 0; i < size; i++) {
                TreeNode *cur = q.front();
                tmp.push_back(cur->val);
                q.pop();
                if (cur->left != NULL) q.push(cur->left);
                if (cur->right != NULL) q.push(cur->right);
            }
            stack.push(tmp);
        }
        while (!stack.empty()) {
            res.push_back(stack.top());
            stack.pop();
        }
        return res;
    }
};
