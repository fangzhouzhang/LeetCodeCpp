//
// Created by Fangzhou Zhang on 2020/5/15.
//
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        int n = source.size();
        int idx = 0;
        bool canAdd = true;
        string add;
        while (idx < n) {
            string &cur = source[idx];
            if (canAdd) {
                string newStr;
                add = newStr;
            }
            int size = cur.size();
            int i = 0;
            while (i < size) {
                char c = cur[i];
                if (canAdd && c == '\/') {
                    if (i + 1 < size && cur[i + 1] == '\/') {
                        i = size;
                    } else if (i + 1 < size && cur[i + 1] == '*') {
                        canAdd = false;
                        i += 1;
                    }
                } else if (!canAdd && c == '*') {
                    if (i + 1 < size && cur[i + 1] == '\/') {
                        i += 2;
                        canAdd = true;
                        continue;
                    }
                }
                if (i < size && canAdd) {
                    add.push_back(cur[i]);
                }
                i++;
            }
            if (add.size() > 0 && canAdd) res.push_back(add);
            idx++;
        }
        return res;
    }
};
