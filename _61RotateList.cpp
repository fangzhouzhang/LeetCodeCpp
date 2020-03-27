//
// Created by Fangzhou Zhang on 2020/3/27.
//
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0) return head;
        ListNode *cur = head;
        int size = 1;
        while (cur != NULL && cur->next != NULL) {
            size++;
            cur = cur->next;
        }
        k = k % size;
        int remain = size - k;
        cur->next = head;
        int i = 0;
        while (remain > i) {
            cur = cur->next;
            i++;
        }
        ListNode *ret = cur->next;
        cur->next = NULL;
        return ret;
    }
};
