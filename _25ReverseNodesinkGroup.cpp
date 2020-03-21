//
// Created by Fangzhou Zhang on 2020/3/21.
//
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy;
        function<ListNode*()> reverse = [&](){
            int cnt = 0;
            ListNode *cur = head;
            ListNode *end = NULL;
            while (cnt < k && cur != NULL) {
                cnt++;
                end = cur;
                cur = cur->next;
            }
            if (cnt < k) return head;
            ListNode *next_iter_head = end->next;
            ListNode *p = next_iter_head;
            ListNode *c = head;
            while (c != next_iter_head) {
                ListNode *n = c->next;
                c->next = p;
                p = c;
                c = n;
            }
            return p;
        };
        while (head != NULL) {
            ListNode *first = head;
            pre->next = reverse();
            pre = first;
            head = first->next;
        }

        return dummy->next;
    }
};
