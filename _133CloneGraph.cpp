//
// Created by Fangzhou Zhang on 2020/3/3.
//
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return node;
        unordered_map<Node*, Node*> map;
        bfs(map, node);
        copyNeighbors(map);
        return map[node];
    }

    void bfs(unordered_map<Node*, Node*>& map, Node*& node) {
        queue<Node*> q;
        unordered_set<Node*> set;
        q.push(node);
        set.insert(node);
        while (q.size() > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node *cur = q.front();
                q.pop();
                map[cur] = new Node(cur->val);
                vector<Node*>& neighbors = cur->neighbors;
                for (auto &x : neighbors) {
                    if (set.find(x) == set.end()) {
                        q.push(x);
                        set.insert(x);
                    }
                }
            }
        }
    }

    void copyNeighbors(unordered_map<Node*, Node*>& map) {
        for (auto &x : map) {
            Node *ori = x.first;
            Node *cpy = x.second;
            vector<Node*>& neighbors = ori->neighbors;
            for (auto &y : neighbors) {
                cpy->neighbors.push_back(map[y]);
            }
        }
    }
};
