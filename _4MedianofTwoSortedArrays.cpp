//
// Created by Fangzhou Zhang on 2020/3/18.
//
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        //now nums1.size <= nums2.size
        int start = 0, end = nums1.size();
        int total = (nums1.size() + nums2.size());
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int left_1 = mid - 1 < 0 ? INT_MIN : nums1[mid - 1];
            int right_1 = mid >= nums1.size() ? INT_MAX : nums1[mid];
            int n2 = total / 2 - mid;
            int left_2 = n2 - 1 < 0 ? INT_MIN : nums2[n2 - 1];
            int right_2 = n2 >= nums2.size() ? INT_MAX : nums2[n2];
            if (left_1 > right_2) {
                end = mid - 1;
            } else if (left_2 > right_1) {
                start = mid + 1;
            } else {
                if (total % 2 == 0) {
                    return (max(left_1, left_2) + min(right_1, right_2)) * 1.0 / 2;
                } else {
                    return min(right_1, right_2) * 1.0;
                }
            }
        }
        return -1;
    }
};
