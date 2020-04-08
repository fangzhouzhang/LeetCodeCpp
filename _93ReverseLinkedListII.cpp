//
// Created by Fangzhou Zhang on 2020/4/8.
//
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        int cnt = 0;
        ListNode *first_tail = dummy;
        while (cnt != m - 1) {
            first_tail = first_tail->next;
            cnt++;
        }
        ListNode *first = first_tail->next;
        ListNode *last = first_tail;
        while (cnt != n) {
            last = last->next;
            cnt++;
        }
        ListNode *second_head = last->next;

        //reverse
        first_tail->next = NULL;
        last->next = NULL;

        ListNode *cur = first;
        ListNode *pre = NULL;
        while (cur != NULL) {
            ListNode *n = cur->next;
            cur->next = pre;
            pre = cur;
            cur = n;
        }
        first_tail->next = last;
        first->next = second_head;
        return dummy->next;
    }
};
