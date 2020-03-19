//
// Created by Fangzhou Zhang on 2020/3/19.
//

class Solution {
public:
    int myAtoi(string str) {
        if (str.size() == 0) return 0;
        long res = 0;
        int sign = 1;
        bool met_first = false;
        int idx = 0;
        function<int()> calc = [&](){
            res *= sign;
            if (res <= INT_MIN) return INT_MIN;
            else if (res >= INT_MAX) return INT_MAX;
            else return (int)res;
        };
        while (idx < str.size()) {
            if (met_first) {//met non-whitespace char
                if (isdigit(str[idx])) {
                    res = res * 10 + (int)(str[idx] - '0');
                    idx++;
                } else return calc();
            } else {//not meet non-whitespace char
                if (isdigit(str[idx])) {
                    res += (int)(str[idx] - '0');
                    idx++;
                    met_first = true;
                } else if (str[idx] == '+' || str[idx] == '-') {
                    sign = (str[idx] == '+') ? 1 : -1;
                    idx++;
                    met_first = true;
                } else if (str[idx] == ' ') {
                    idx++;
                } else {
                    return calc();
                }
            }
            if (res * sign <= INT_MIN || res * sign >= INT_MAX) return res * sign <= INT_MIN ? INT_MIN : INT_MAX;
        }
        return calc();
    }
};
