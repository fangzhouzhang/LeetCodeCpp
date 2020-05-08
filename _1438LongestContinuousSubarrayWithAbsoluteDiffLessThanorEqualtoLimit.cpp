//
// Created by Fangzhou Zhang on 2020/5/8.
//
struct cmp {
    template<typename T>
    bool operator()(const T &a, const T &b) const{
        if (a.second != b.second) {
            return a.second < b.second;
        } else {
            return a.first < b.first;
        }
    }
};
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int min_v = INT_MAX, max_v = INT_MIN, res = 0;
        int slow = 0, fast = 0;
        set<pair<int, int>, cmp> set;
        while (fast < nums.size()) {
            set.insert(make_pair(fast, nums[fast]));
            while (!set.empty() && set.rbegin()->second - set.begin()->second > limit) {
                set.erase(make_pair(slow, nums[slow]));
                slow++;
            }
            res = max(res, fast - slow + 1);
            fast++;
        }
        return res;
    }
};
