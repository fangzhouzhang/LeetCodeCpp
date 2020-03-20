//
// Created by Fangzhou Zhang on 2020/3/19.
//
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *fast = dummy;
        int cnt = 0;
        while (cnt < n + 1) {
            fast = fast->next;
            cnt++;
        }
        ListNode *slow = dummy;
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *del = slow->next;
        slow->next = del->next;
        del = NULL;
        return dummy->next;
    }
};
