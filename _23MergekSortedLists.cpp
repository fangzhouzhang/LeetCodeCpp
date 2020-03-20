//
// Created by Fangzhou Zhang on 2020/3/20.
//
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        function<ListNode*(ListNode*, ListNode*)> merge_two = [&](ListNode *l1, ListNode *l2){

            ListNode *dummy = new ListNode(-1);
            ListNode *cur = dummy;
            while (l1 != NULL && l2 != NULL) {
                if (l1->val < l2->val) {
                    cur->next = l1;
                    l1 = l1->next;
                    cur = cur->next;
                } else {
                    cur->next = l2;
                    l2 = l2->next;
                    cur = cur->next;
                }
            }
            while (l1 != NULL) {
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            }
            while (l2 != NULL) {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
            return dummy->next;
        };

        function<ListNode*(int, int)> merge_k = [&](int start, int end){
            if (start == end) return lists[start];
            int mid = start + (end - start) / 2;
            ListNode *h1 = merge_k(start, mid);
            ListNode *h2 = merge_k(mid + 1, end);
            return merge_two(h1, h2);
        };
        if (lists.size() == 0) return NULL;
        return merge_k(0, lists.size() - 1);
    }
};
