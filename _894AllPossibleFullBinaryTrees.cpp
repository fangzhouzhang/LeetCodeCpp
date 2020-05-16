//
// Created by Fangzhou Zhang on 2020/5/15.
//
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> res;
        if (N % 2 == 0) return res;
        return dfs(N);
    }

    vector<TreeNode*> dfs(int n) {
        vector<TreeNode*> res;
        if (n == 1) {
            res.push_back(new TreeNode(0));
            return res;
        }
        for (int i = 1; i <= n - 1; i += 2) {
            vector<TreeNode*> left = dfs(i);

            vector<TreeNode*> right = dfs(n - 1 - i);
            for (int k = 0; k < left.size(); k++) {
                for (int j = 0; j < right.size(); j++) {
                    TreeNode *root = new TreeNode(0);
                    root->left = left[k];
                    root->right = right[j];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
