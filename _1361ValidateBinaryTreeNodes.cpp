//
// Created by Fangzhou Zhang on 2020/2/23.
//
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<vector<int>> map;
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            if (leftChild[i] != -1) {
                tmp.push_back(leftChild[i]);
                indegree[leftChild[i]]++;
                if (indegree[leftChild[i]] > 1) return false;
            }
            if (rightChild[i] != -1) {
                tmp.push_back(rightChild[i]);
                indegree[rightChild[i]]++;
                if (indegree[rightChild[i]] > 1) return false;
            }
            map.push_back(tmp);
        }
        queue<int> q;
        int cnt = 0;
        for(auto& a : indegree) {
            if (a == 0) {
                cnt++;
                q.push(a);
            }
            if (cnt > 1) return false;
        }
        if (cnt == 0) return false;
        return true;
    }
};
