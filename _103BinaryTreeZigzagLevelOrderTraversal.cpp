//
// Created by Fangzhou Zhang on 2020/4/9.
//
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        deque<TreeNode*> q;
        q.push_back(root);
        int cnt = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> tmp;
            for (int i = 0; i < size; i++) {
                TreeNode *cur = NULL;
                if (cnt % 2 == 0) {
                    cur = q.front();
                    q.pop_front();
                    if (cur->left != NULL) q.push_back(cur->left);
                    if (cur->right != NULL) q.push_back(cur->right);
                } else {
                    cur = q.back();
                    q.pop_back();
                    if (cur->right != NULL) q.push_front(cur->right);
                    if (cur->left != NULL) q.push_front(cur->left);
                }
                tmp.push_back(cur->val);
            }
            cnt++;
            res.push_back(tmp);
        }
        return res;
    }
};
