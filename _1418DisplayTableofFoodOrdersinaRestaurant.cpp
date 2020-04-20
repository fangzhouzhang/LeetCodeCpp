//
// Created by Fangzhou Zhang on 2020/4/19.
//
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<vector<string>> res;
        if (orders.size() == 0) return res;
        map<string, int> header;
        for (vector<string> &o : orders) {
            header[o[2]] = 0;
        }
        int idx = 0;
        vector<string> tmp;
        tmp.push_back("Table");
        for (map<string, int>::iterator it = header.begin(); it != header.end(); it++) {
            tmp.push_back(it->first);
            it->second = idx++;
        }
        res.push_back(tmp);
        map<int, vector<int>> nums;
        for (vector<string> &o : orders) {
            int idx = header[o[2]];
            int table = stoi(o[1]);
            if (nums[table].size() == 0) nums[table].resize(header.size());
            nums[table][idx]++;
        }
        for (map<int, vector<int>>::iterator it = nums.begin(); it != nums.end(); it++) {
            vector<string> t;
            t.push_back(to_string(it->first));
            vector<int> &ns = it->second;
            for (int &n : ns) {
                t.push_back(to_string(n));
            }
            res.push_back(t);
        }
        return res;
    }
};
