//
// Created by Fangzhou Zhang on 2020/4/15.
//
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (NULL == head) return NULL;
        if (NULL == head->next) return new TreeNode(head->val);
        ListNode *pre = NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};
