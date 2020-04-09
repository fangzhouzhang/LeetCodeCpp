//
// Created by Fangzhou Zhang on 2020/4/9.
//
class Solution {
public:
    void recoverTree(TreeNode* root) {
        if (root == NULL) return;
        vector<TreeNode*> nodes;
        vector<int> vals;
        function<void(TreeNode*)> inorder = [&](TreeNode* root){
            if (root == NULL) return;
            inorder(root->left);
            nodes.push_back(root);
            vals.push_back(root->val);
            inorder(root->right);
        };
        inorder(root);
        sort(vals.begin(), vals.end());
        for (int i = 0; i < nodes.size(); i++) nodes[i]->val = vals[i];
        return;
    }

    void recoverTree1(TreeNode* root) {
        if (root == NULL) return;
        TreeNode *pre = NULL;
        TreeNode *first = NULL;
        TreeNode *second = NULL;
        function<void(TreeNode*)> inorder = [&](TreeNode* root){
            if (root == NULL) return;
            inorder(root->left);
            if (pre != NULL && pre->val > root->val) {
                if (first == NULL) first = pre;
                second = root;
            }
            pre = root;
            inorder(root->right);
        };
        inorder(root);
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
        return;
    }
};
