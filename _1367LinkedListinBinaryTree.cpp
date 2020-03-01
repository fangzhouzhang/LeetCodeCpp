//
// Created by Fangzhou Zhang on 2020/3/1.
//
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (head == NULL && root == NULL) return true;
        if (head == NULL || root == NULL) return false;
        bool left = isSubPath(head, root->left);
        bool right = isSubPath(head, root->right);
        return dfs(head, root) || left || right;
    }

    bool dfs(ListNode* head, TreeNode* root) {
        if (head == NULL) return true;
        if (root == NULL) return false;
        return head->val == root->val && (dfs(head->next, root->left) || dfs(head->next, root->right));
    }
};
