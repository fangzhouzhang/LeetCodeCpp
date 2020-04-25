//
// Created by Fangzhou Zhang on 2020/4/24.
//
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set;
        for (string s : wordList) set.insert(s);
        set.insert(beginWord);
        if (set.find(endWord) == set.end()) return 0;

        int cnt = 2;
        unordered_set<string> q1;
        unordered_set<string> q2;
        unordered_set<string> dedup;
        q1.insert(beginWord);
        q2.insert(endWord);
        dedup.insert(beginWord);
        dedup.insert(endWord);
        while (!q1.empty() && !q2.empty()) {
            if (q1.size() > q2.size()) {
                unordered_set<string> t = q1;
                q1 = q2;
                q2 = t;
            }
            unordered_set<string> tmp;
            for (string s : q1) {
                int n = s.size();
                string s1(s);
                for (int i = 0; i < n; i++) {
                    char old = s1[i];
                    for (char cur = 'a'; cur <= 'z'; cur++) {
                        if (old == cur) continue;
                        s1[i] = cur;
                        if (q2.find(s1) != q2.end()) {
                            return cnt;
                        }
                        if (set.find(s1) == set.end()) continue;
                        if (dedup.find(s1) == dedup.end()) {
                            dedup.insert(s1);
                            tmp.insert(s1);
                        }
                    }
                    s1[i] = old;
                }
            }
            cnt++;
            q1 = tmp;
        }
        return 0;
    }
};
