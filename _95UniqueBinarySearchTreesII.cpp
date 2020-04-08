//
// Created by Fangzhou Zhang on 2020/4/8.
//
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return dfs(1, n);
    }

    vector<TreeNode*> dfs(int start, int end) {
        if (start > end) return {NULL};
        if (start == end) return {new TreeNode(start)};
        vector<TreeNode*> res;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = dfs(start, i - 1);
            vector<TreeNode*> right = dfs(i + 1, end);
            for (TreeNode *l : left) {
                for (TreeNode *r : right) {
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
