//
// Created by Fangzhou Zhang on 2020/3/19.
//
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        vector<string> nums = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (digits.size() == 0) return res;
        string tmp;
        function<void(int)> dfs = [&](int idx){
            if (idx == digits.size()) {
                res.push_back(tmp);
                return;
            }
            for (char &c: nums[digits[idx] - '0']) {
                tmp.push_back(c);
                dfs(idx + 1);
                tmp.pop_back();
            }
        };
        dfs(0);
        return res;
    }
};
