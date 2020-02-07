//
// Created by Fangzhou Zhang on 2020/2/7.
//
class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        vector<TreeNode*> res (2, NULL);
        if (!root) return res;
        if (root->val <= V) {
            //connect small part of res
            vector<TreeNode*> ret = splitBST(root->right, V);
            root->right = ret[0];
            res[0] = root;
            res[1] = ret[1];
        } else {
            vector<TreeNode*> ret = splitBST(root->left, V);
            root->left = ret[1];
            res[0] = ret[0];
            res[1] = root;
        }
        return res;
    }
};
