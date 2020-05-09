//
// Created by Fangzhou Zhang on 2020/5/9.
//
class Solution {
public:
    int maxDiff(int num) {
        string str = to_string(num);
        int n = str.size();
        vector<int> n1(n, 0);
        vector<int> n2(n, 0);
        int idx = n - 1;
        int pre = -1;
        bool same = true;
        while (num != 0) {
            n1[idx] = num % 10;
            n2[idx] = n1[idx];
            if (idx == n - 1) {
                pre = n1[idx];
            } else {
                if (n1[idx] != pre) {
                    same = false;
                }
                pre = n1[idx];
            }
            num /= 10;
            idx--;
        }
        if (same) {
            int res = 0;
            for (int i = 0; i < n; i++) {
                res = res * 10 + 8;
            }
            return res;
        } else {
            int k = 0;
            while (k < n && n1[k] == 9) k++;
            int highChange = n1[k];
            int high = 0;
            for (int i = 0; i < n; i++) {
                if (highChange == n1[i]) {
                    n1[i] = 9;
                }
                high = high * 10 + n1[i];
            }
            int low = 0;
            int lowChange;
            bool changeOne = false;
            if (n2[0] >= 2) {
                lowChange = n2[0];
                changeOne = true;
            } else {
                int l = 0;
                while (l < n && (n2[l] == n2[0] || n2[l] == 0)) l++;
                lowChange = (l == n) ? 0 : n2[l];
            }
            for (int i = 0; i < n; i++) {
                if (lowChange == n2[i]) {
                    if (changeOne) n2[i] = 1;
                    else n2[i] = 0;
                }
                low = low * 10 + n2[i];
            }
            return high - low;
        }
    }
};
