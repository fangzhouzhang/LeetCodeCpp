//
// Created by Fangzhou Zhang on 2020/4/5.
//
#pragma GCC optimize ("O3,unroll-loops")
static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        stack<TreeNode*> stack;
        TreeNode *cur = root;
        while (stack.size() > 0 || cur != NULL) {
            while (cur != NULL) {
                stack.push(cur);
                cur = cur->left;
            }

            cur = stack.top();
            stack.pop();
            res.push_back(cur->val);
            // if (cur->right != NULL) stack.push(cur->right);
            cur = cur->right;
        }
        return res;
    }
};
