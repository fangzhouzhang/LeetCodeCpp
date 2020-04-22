//
// Created by Fangzhou Zhang on 2020/4/21.
//
class Solution {
public:
    Node* connect(Node* root) {
        if (NULL == root) return root;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            Node *pre = NULL;
            for (int i = 0; i < size; i++) {
                Node *cur = q.front();
                q.pop();

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);

                if (NULL != pre) {
                    pre->next = cur;
                }
                pre = cur;
            }
        }
        return root;
    }
};
