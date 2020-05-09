//
// Created by Fangzhou Zhang on 2020/5/9.
//
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        vector<int> m1(26, 0);
        vector<int> m2(26, 0);
        for (char c : s1) {
            int idx = c - 'a';
            m1[idx]++;
        }
        for (char c : s2) {
            int idx = c - 'a';
            if (m1[idx] > 0) {
                m1[idx]--;
            } else {
                m2[idx]++;
            }
        }
        int i1 = 0;
        while (i1 < 26 && m1[i1] == 0) {
            i1++;
        }
        int i2 = 0;
        while (i2 < 26 && m2[i2] == 0) {
            i2++;
        }
        if (i1== 26 && i1 == i2) return true;
        if (i1 < i2) {
            return judge(m1, i1, m2, i2);
        } else {
            return judge(m2, i2, m1, i1);
        }
    }

    bool judge(vector<int> &a, int i1, vector<int> &b, int i2) {
        while (i1 < 26 && i2 < 26) {
            // cout << i1 << "   " << i2 << endl;
            if (i1 <= i2) {
                a[i1]--;
                b[i2]--;
            } else return false;
            while (i1 < 26 && a[i1] == 0) i1++;
            while (i2 < 26 && b[i2] == 0) i2++;
        }
        return true;

    }
};
