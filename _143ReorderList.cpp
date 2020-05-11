//
// Created by Fangzhou Zhang on 2020/5/10.
//
class Solution {
public:
    void reorderList(ListNode* head) {
        if (NULL == head) return;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *second = slow->next;
        slow->next = NULL;

        ListNode *h = reverse(second);

        while (head != NULL && h != NULL) {
            ListNode *t1 = head->next;
            ListNode *t2 = h->next;
            head->next = h;
            h->next = t1;

            head = t1;
            h = t2;
        }
    }

    ListNode * reverse(ListNode *head) {
        if (NULL == head) return NULL;
        ListNode *cur = head;
        ListNode *pre = NULL;
        while (cur != NULL) {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};
