//
// Created by Fangzhou Zhang on 2020/3/16.
//
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        if (nums.size() == 0) return res;
        vector<pair<int, int>> elems(nums.size());//1. val 2. idx
        for (int i = 0; i < nums.size(); i++) elems[i] = {nums[i], i};
        vector<pair<int, int>> tmp(nums.size());
        function<void(int, int, int)> merge = [&](int start, int mid, int end){
            int cnt = 0;
            int left = start;
            int right = mid + 1;
            int tmp_idx = start;
            while (left <= mid && right <= end) {
                if (elems[left].first > elems[right].first) {
                    cnt++;
                    tmp[tmp_idx++] = elems[right++];
                } else {
                    res[elems[left].second] += cnt;
                    tmp[tmp_idx++] = elems[left++];
                }
            }

            while (left <= mid) {
                res[elems[left].second] += cnt;
                tmp[tmp_idx++] = elems[left++];
            }
            while (right <= end) {
                tmp[tmp_idx++] = elems[right++];
            }
            tmp_idx = start;
            while (tmp_idx <= end) {
                elems[tmp_idx] = tmp[tmp_idx];
                tmp_idx++;
            }
        };

        function<void(int, int)> mergeSort = [&](int start, int end){
            if (start >= end) return;
            int mid = start + (end - start) / 2;
            mergeSort(start, mid);
            mergeSort(mid + 1, end);
            merge(start, mid, end);
        };
        mergeSort(0, nums.size() - 1);
        return res;
    }
};
