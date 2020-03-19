//
// Created by Fangzhou Zhang on 2020/3/19.
//
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long res = 0;
        long n = (long)x;
        while (n > 0) {
            res = res * 10 + (n % 10);
            n /= 10;
        }
        return res == x;
    }
};
