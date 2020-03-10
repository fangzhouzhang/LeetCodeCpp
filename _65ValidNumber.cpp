//
// Created by Fangzhou Zhang on 2020/3/9.
//
class Solution {
public:
    bool isNumber(string s) {
        if (s.size() == 0) return false;
        while(s[0]==' ')  s.erase(0,1);//delete the  prefix whitespace
        while(s[s.length()-1]==' ') s.erase(s.length()-1, 1);//delete the suffix whitespace
        int e_num = 0;
        int e_pos = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'e') {
                e_num++;
                e_pos = i;
            } else if (isalpha(s[i])) return false;
        }
        if (e_num > 1) return false;
        if (e_num == 0) {
            return judge(0, s.size() - 1, s, 1);
        } else {
            return judge(0, e_pos - 1, s, 1) && judge(e_pos + 1, s.size() - 1, s, 0);
        }
    }

    bool judge(int start, int end, string s, int d) {
        bool metSign = false;
        int countD = 0;
        bool num = false;
        int i = start;
        if (s[i] == '-' || s[i] == '+') i++;
        while (i <= end) {
            if (s[i] == '.') countD++;
            else if (isdigit(s[i])) num = true;
            else return false;
            i++;
        }
        return num && countD <= d;
    }
};
