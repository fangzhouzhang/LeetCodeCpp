//
// Created by Fangzhou Zhang on 2020/2/28.
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) return NULL;
        if (l1 == NULL || l2 == NULL) return l1 == NULL ? l2 : l1;
        int carry = 0;
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        while (l1 != NULL && l2 != NULL) {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            int digit = sum % 10;
            cur->next = new ListNode(digit);
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL) {
            int sum = l1->val + carry;
            carry = sum / 10;
            int digit = sum % 10;
            cur->next = new ListNode(digit);
            cur = cur->next;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            int sum = l2->val + carry;
            carry = sum / 10;
            int digit = sum % 10;
            cur->next = new ListNode(digit);
            cur = cur->next;
            l2 = l2->next;
        }
        if (carry != 0) {
            cur->next= new ListNode(carry);
            cur = cur->next;
        }
        return head->next;
    }
};
