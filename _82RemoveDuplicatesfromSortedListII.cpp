//
// Created by Fangzhou Zhang on 2020/4/4.
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *dummy = new ListNode(-1);
        ListNode *pre = dummy;
        ListNode *cur = head;
        ListNode *n = head->next;

        while (cur != NULL) {
            if (n != NULL) {
                if (cur->val == n->val) {
                    while (n != NULL && cur->val == n->val) {
                        n = n->next;
                    }
                    cur = n;
                    if (n != NULL) n = n->next;
                } else {
                    pre->next = cur;
                    pre = pre->next;
                    cur = n;
                    n = n->next;
                    pre->next = NULL;
                }
            } else {
                pre->next = cur;
                pre = pre->next;
                cur = n;
                pre->next = NULL;
            }
        }
        return dummy->next;
    }
};
