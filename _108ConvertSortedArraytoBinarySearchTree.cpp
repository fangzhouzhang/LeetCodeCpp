//
// Created by Fangzhou Zhang on 2020/4/13.
//
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }

    TreeNode * dfs(vector<int>& nums, int start, int end) {
        if (start > end) return (TreeNode *)NULL;
        if (start == end) return new TreeNode(nums[start]);
        int mid = start + (end - start) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = dfs(nums, start, mid - 1);
        root->right = dfs(nums, mid + 1, end);
        return root;
    }
};
