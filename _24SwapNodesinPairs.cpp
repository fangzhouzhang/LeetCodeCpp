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

    ListNode* iter_swapPairs(ListNode* head) {
            if (head == NULL || head->next == NULL) return head;
            ListNode *dummy = new ListNode(-1);
            dummy->next = head;
            ListNode *pre = dummy;
            while (head != NULL && head->next != NULL) {
                    ListNode *first = head;
                    ListNode *second = head->next;

                    pre->next = second;
                    first->next = second->next;
                    second->next = first;

                    pre = first;
                    head = first->next;
            }
            return dummy->next;
    }
};
