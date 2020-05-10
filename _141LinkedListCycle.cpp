//
// Created by Fangzhou Zhang on 2020/5/9.
//
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (NULL == head) return false;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
