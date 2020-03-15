//
// Created by Fangzhou Zhang on 2020/3/14.
//

class Solution {
public:
    string minWindow(string S, string T) {
        if (S.size() < T.size()) return "";
        int slen = S.size(), tlen = T.size();
        int start = -1, min_len = INT_MAX;
        int i = 0, j = 0;
        while (i < slen) {
            if (S[i] == T[j]) {
                j++;
                if (j == tlen) {
                    //i is at last matching idx
                    int end = i;
                    //j is out of boundary
                    j--;
                    while (j >= 0) {
                        if (S[i] == T[j]) j--;
                        i--;
                    }
                    //i is one char before the string matching T
                    i++;
                    //j == -1
                    j++;
                    if (end - i + 1 < min_len) {
                        start = i;
                        min_len = end - i + 1;
                    }
                }
            }
            i++;
        }
        return start == -1 ? "" : S.substr(start, min_len);
    }
};