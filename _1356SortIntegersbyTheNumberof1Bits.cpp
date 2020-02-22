//
// Created by Fangzhou Zhang on 2020/2/22.
//
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> res(arr.size(), 0);
        vector<pair<int, int>> tmp;
        for (auto num : arr) {
            int n = num;
            int ones = 0;
            while (n > 0) {
                if ((n & 1) == 1) ones++;
                n >>= 1;
            }
            tmp.push_back({num, ones});
        }
        sort(tmp.begin(), tmp.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            if (a.second != b.second) {
                return a.second < b.second;
            } else {
                return a.first < b.first;
            }
        });
        for (int i = 0; i < tmp.size(); i++) {
            res[i] = tmp[i].first;
        }
        return res;
    }
};
