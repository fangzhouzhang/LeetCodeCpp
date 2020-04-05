//
// Created by Fangzhou Zhang on 2020/4/4.
//
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return head;
        ListNode *d1 = new ListNode(-1);
        ListNode *p1 = d1;

        ListNode *d2 = new ListNode(-1);
        ListNode *p2 = d2;

        ListNode *cur = head;
        while (cur != NULL) {
            if (cur->val < x) {
                p1->next = cur;
                p1 = p1->next;
                cur = cur->next;
                p1->next = NULL;
            } else {
                p2->next = cur;
                p2 = p2->next;
                cur = cur->next;
                p2->next = NULL;
            }
        }
        p1->next = d2->next;
        return d1->next;
    }
};
