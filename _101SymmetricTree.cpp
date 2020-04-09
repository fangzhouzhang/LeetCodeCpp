//
// Created by Fangzhou Zhang on 2020/4/9.
//
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        function<bool(TreeNode*, TreeNode*)> dfs = [&](TreeNode* a, TreeNode* b){
            if (a == NULL && b == NULL) return true;
            if (a == NULL || b == NULL) return false;
            if (a->val != b->val) return false;
            return dfs(a->left, b->right) && dfs(a->right, b->left);
        };
        return dfs(root, root) && dfs(root, root) ;
    }
};
