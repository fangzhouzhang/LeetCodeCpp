//
// Created by Fangzhou Zhang on 2020/3/9.
//
class Solution {
public:
    bool isNumber(string s) {
        if (s.size() == 0) return false;
        int e_pos = -1;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == 'e' && e_pos == -1) e_pos = i;
            else if (c == 'e') return false;
        }
        int first = 0, last = s.size() - 1;
        while (first < s.size() && s[first] == ' ') first++;
        while (last >= 0 && s[last] == ' ') last--;
        function<bool(int, int, int)> judge = [&](int start, int end, int count){
            int dot_count = 0;
            bool num = false;
            if (s[start] == '+' || s[start] == '-') start++;
            while (start <= end) {
                if (isdigit(s[start])) {
                    num = true;
                    start++;
                } else if (s[start] == '.') {
                    dot_count++;
                    if (dot_count > count) return false;
                    start++;
                } else return false;
            }
            return num;
        };
        if (e_pos == -1) return judge(first, last, 1);
        return judge(first, e_pos - 1, 1) && judge(e_pos + 1, last, 0);
    }
};
