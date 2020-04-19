//
// Created by Fangzhou Zhang on 2020/4/19.
//
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        if ((croakOfFrogs.size() == 0) || (croakOfFrogs.size() % 5 != 0)) return -1;
        int res = 0;
        vector<int> cs;
        vector<int> rs;
        vector<int> os;
        vector<int> as;
        vector<int> ks;
        for (int i = 0; i < croakOfFrogs.size(); i++) {
            if (croakOfFrogs[i] == 'c') {
                cs.push_back(i);
            } else if (croakOfFrogs[i] == 'r') {
                rs.push_back(i);
            } else if (croakOfFrogs[i] == 'o') {
                os.push_back(i);
            } else if (croakOfFrogs[i] == 'a') {
                as.push_back(i);
            } else if (croakOfFrogs[i] == 'k') {
                if (cs.size() > res) res = cs.size();
                if (as.empty()) return -1;
                int i1 = b_s(as, i);
                int p1 = as[i1];
                if (i1 == -1) return -1;
                as.erase(as.begin() + i1);

                int i2 = b_s(os, p1);
                if (i2 == -1) return -1;
                int p2 = os[i2];
                os.erase(os.begin() + i2);

                int i3 = b_s(rs, p2);
                if (i3 == -1) return -1;
                int p3 = rs[i3];
                rs.erase(rs.begin() + i3);

                int i4 = b_s(cs, p3);
                if (i4 == -1) return -1;
                int p4 = cs[i4];
                cs.erase(cs.begin() + i4);
            }
        }
        if (!cs.empty() || !rs.empty() ||!os.empty() ||!as.empty()) return -1;
        return res;
    }

    int b_s(vector<int> &n, int t) {
        int start = 0, end = n.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (n[mid] == t) end = mid - 1;
            else if (n[mid] < t) start = mid + 1;
            else end = mid - 1;
        }
        if (end < 0 || n[end] >= t) return -1;
        return end;
    }
};
