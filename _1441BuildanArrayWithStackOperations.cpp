//
// Created by Fangzhou Zhang on 2020/5/9.
//
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int len = target.size();
        int idx = 0;
        vector<string> res;
        for (int i = 1; i <= n && idx < len; i++) {
            if (target[idx] == i) {
                res.push_back("Push");
                idx++;
            }
            else {
                res.push_back("Push");
                res.push_back("Pop");
            }
        }
        return res;
    }
};
