//
// Created by Fangzhou Zhang on 2020/3/20.
//
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }

        while (l1 != NULL) {
            cur->next = l1;
            l1 = l1->next;
            cur = cur->next;
        }

        while (l2 != NULL) {
            cur->next = l2;
            l2 = l2->next;
            cur = cur->next;
        }

        return dummy->next;
    }
};
