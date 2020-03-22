//
// Created by Fangzhou Zhang on 2020/3/22.
//
class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        vector<int> arr(n1 + n2 + 1, 0);
        int idx = arr.size() - 1;
        for (int i = n2 - 1; i >= 0; i--, idx--) {
            int cur_idx = idx;
            for (int j = n1 - 1; j >= 0; j--, cur_idx--) {
                int v2 = num2[i] - '0';
                int v1 = num1[j] - '0';
                int product = v1 * v2;

                int cur = product + arr[cur_idx];
                arr[cur_idx] = cur % 10;
                arr[cur_idx - 1] += cur / 10;
            }
        }
        string res;
        bool lead_zero = true;
        for (int i = 0; i < arr.size(); i++) {

            if (arr[i] == 0 && lead_zero) continue;
            else {
                res.push_back((char)(arr[i] + '0'));
                lead_zero = false;
            }
        }
        return res.size() == 0 ? "0" : res;
    }
};
