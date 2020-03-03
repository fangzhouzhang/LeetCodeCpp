//
// Created by Fangzhou Zhang on 2020/3/2.
//
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return head;
        unordered_map<Node*, Node*> map;
        Node *cur = head;
        while (cur != NULL) {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        unordered_map<Node*, Node*>::iterator it = map.begin();
        while (it != map.end()) {
            Node *ori = it->first;
            Node *cpy = it->second;
            if (ori->next != NULL) cpy->next = map[ori->next];
            if (ori->random != NULL) cpy->random = map[ori->random];
            it++;
        }
        return map[head];
    }
};
