//
// Created by Fangzhou Zhang on 2020/4/18.
//
class Solution {
public:
    string getHappyString(int n, int k) {
        string res;
        vector<int> nums(n + 1, 0);
        nums[1] = 3;
        for (int i = 2; i < n + 1; i++) nums[i] = nums[i - 1] * 2;
        if (k > nums[n]) return "";
        k--;
        char tmp = NULL;
        while (n > 0) {
            if (NULL == tmp) {
                int rem = k / (nums[n] / 3);
                tmp = (char)('a' + rem);
                res.push_back(tmp);
                k -= rem * (nums[n] / 3);

            } else {
                int rem = k / (nums[n] / 3);
                int count = 0;
                for (int i = 0; i < 3; i++) {
                    char cur = (char)(i + 'a');
                    if (cur == tmp) continue;
                    if (count == rem) {
                        res.push_back(cur);
                        tmp = cur;
                        break;
                    } else count++;
                }
                k -= rem * (nums[n] / 3);
            }
            n--;
        }
        return res;
    }
};
