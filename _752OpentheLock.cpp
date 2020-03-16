//
// Created by Fangzhou Zhang on 2020/3/16.
//
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        vector<vector<char>> neighbors = {{'9', '1'}, {'0', '2'}, {'1', '3'}, {'2', '4'}, {'3', '5'}, {'4', '6'}, {'5', '7'}, {'6', '8'},{'7', '9'}, {'8', '0'}};
        unordered_set<string> forbid;
        unordered_set<string> dedup;
        for (string &s : deadends) forbid.insert(s);
        if (forbid.find("0000") != forbid.end()) return -1;
        queue<string> q;
        q.push("0000");
        dedup.insert("0000");
        int res = 0;
        while (q.size() != 0) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                string cur = q.front();
                if (cur.compare(target) == 0) return res;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    char tmp = cur[i];
                    int nei_idx = cur[i] - '0';
                    for (char &c : neighbors[nei_idx]) {
                        cur[i] = c;
                        if (dedup.find(cur) == dedup.end() && forbid.find(cur) == forbid.end()) {
                            q.push(cur);
                            dedup.insert(cur);
                        }
                    }
                    cur[i] = tmp;
                }
            }
            res++;
        }
        return -1;
    }
};
