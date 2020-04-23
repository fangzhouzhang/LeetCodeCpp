//
// Created by Fangzhou Zhang on 2020/4/23.
//
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0) return true;
        int start = 0, end = s.size() - 1;
        while (start <= end) {
            while (start <= end && !isalpha(s[start]) && !isdigit(s[start])) start++;
            while (start <= end && !isalpha(s[end]) && !isdigit(s[end])) end--;
            if (start <= end) {
                if (tolower(s[start]) != tolower(s[end])) return false;
                start++;
                end--;
            }
        }
        return true;
    }
};
