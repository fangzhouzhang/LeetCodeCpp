//
// Created by Fangzhou Zhang on 2020/2/23.
//
int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        if (date1 > date2) {
            swap(date1, date2);
        }
        int y1 = stoi(date1.substr(0, 4));
        int y2 = stoi(date2.substr(0, 4));
        int m1 = stoi(date1.substr(5, 2));
        int m2 = stoi(date2.substr(5, 2));
        int d1 = stoi(date1.substr(8, 2));
        int d2 = stoi(date2.substr(8, 2));
        int res = 0;
        for (int i = y1; i < y2; i++) {
            if (check(i)) res += 366;
            else res += 365;
        }
        for (int i = 1; i < m1; i++) res -= ((i == 2) ? (check(y1) ? 29 : 28) : mon[i]);
        for (int i = 1; i < m2; i++) res += ((i == 2) ? (check(y2) ? 29 : 28) : mon[i]);
        return res + d2 - d1;
    }
private:
    bool check(int y) {
        if (y % 400 == 0) return true;
        if (y % 100 != 0 && y % 4 == 0) return true;
        return false;
    }
};
