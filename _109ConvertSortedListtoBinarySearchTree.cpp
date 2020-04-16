//
// Created by Fangzhou Zhang on 2020/4/15.
//
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (NULL == head) return (TreeNode *)NULL;
        vector<int> vals;
        while (NULL != head) {
            vals.push_back(head->val);
            head = head->next;
        }
        return dfs(vals, 0, vals.size() - 1);
    }

    TreeNode * dfs(vector<int> vals, int start, int end) {
        if (start > end) return (TreeNode *)NULL;
        if (start == end) return new TreeNode(vals[start]);
        int mid = start + (end - start) / 2;
        TreeNode *root = new TreeNode(vals[mid]);
        root->left = dfs(vals, start, mid - 1);
        root->right = dfs(vals, mid + 1, end);
        return root;
    }
};
