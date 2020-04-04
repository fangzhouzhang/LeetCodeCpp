//
// Created by Fangzhou Zhang on 2020/4/4.
//
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != NULL) {
            if (slow->val == fast->val) {
                slow->next = fast->next;
                fast->next = NULL;
                fast = slow->next;
            } else {
                slow = fast;
                fast = fast->next;
            }
        }
        return head;
    }
};
