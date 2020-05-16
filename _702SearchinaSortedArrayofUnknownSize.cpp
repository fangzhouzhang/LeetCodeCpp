//
// Created by Fangzhou Zhang on 2020/5/15.
//
class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int start = 0, end = 20000;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (reader.get(mid) == INT_MAX) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        int len = end + 1;
        vector<int> nums(len, 0);
        for (int i = 0; i < len; i++) {
            nums[i] = reader.get(i);
        }
        start = 0;
        end = len - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target == nums[mid]) {
                return mid;
            } else if (target < nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }
};
