//
// Created by Fangzhou Zhang on 2020/3/22.
//
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if (nums.size() == 0) return res;
        function<int()> find_first = [&](){
            int start = 0, end = nums.size() - 1;
            while (start + 1 < end) {
                int mid = start + (end - start) / 2;
                if (nums[mid] >= target) end = mid;
                else start = mid;
            }
            if (nums[start] == target) return start;
            else if (nums[end] == target) return end;
            else return -1;
        };
        function<int(int)> find_last = [&](int first){
            int start = max(first, 0), end = nums.size() - 1;
            while (start + 1 < end) {
                int mid = start + (end - start) / 2;
                if (nums[mid] <= target) start = mid;
                else end = mid;
            }
            if (nums[end] == target) return end;
            else if (nums[start] == target) return start;
            else return -1;
        };
        int first = find_first();
        int last = find_last(first);
        return {first, last};
    }
};
