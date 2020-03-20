//
// Created by Fangzhou Zhang on 2020/3/20.
//
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *new_head = swapPairs(head->next->next);
        ListNode *first = head;
        ListNode *second = head->next;
        second->next = first;
        first->next = new_head;
        return second;
    }
};
