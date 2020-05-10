//
// Created by Fangzhou Zhang on 2020/5/9.
//
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (NULL == head) return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *intersect = NULL;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                intersect = slow;
                break;
            }
        }
        if (NULL == intersect) return NULL;
        slow = head;
        while (slow != intersect) {
            slow = slow->next;
            intersect = intersect->next;
        }
        return slow;
    }
};
