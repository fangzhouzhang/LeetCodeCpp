//
// Created by Fangzhou Zhang on 2020/3/29.
//
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows == 0) return false;
        int cols = matrix[0].size();
        if (cols == 0) return false;
        int start = 0, end = rows * cols - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            int r = mid / cols;
            int c = mid % cols;
            if (matrix[r][c] == target) return true;
            else if (matrix[r][c] < target) start = mid;
            else end = mid;
        }
        if (matrix[start / cols][start % cols] == target) return true;
        else if (matrix[end / cols][end % cols] == target) return true;
        else return false;
    }
};
