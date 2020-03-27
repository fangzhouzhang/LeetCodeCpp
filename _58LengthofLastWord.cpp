//
// Created by Fangzhou Zhang on 2020/3/27.
//
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() == 0) return 0;
        bool word_exist = false;
        int res = 0, cur = 0, idx = 0;
        while (idx < s.size()) {
            if (isalpha(s[idx])) {
                word_exist = true;
                cur++;
            } else {
                if (cur != 0) res = cur;
                cur = 0;
            }
            idx++;
        }
        if (!word_exist) return 0;
        return cur == 0 ? res : cur;
    }
};
