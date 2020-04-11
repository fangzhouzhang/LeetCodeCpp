//
// Created by Fangzhou Zhang on 2020/4/10.
//
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 && inorder.size() == 0) return NULL;
        unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); i++) map[inorder[i]] = i;
        function<TreeNode*(int, int,int,int)> dfs = [&](int pstart, int pend, int istart, int iend){
            if (pstart > pend) return (TreeNode *)NULL;
            if (pstart == pend) return new TreeNode(preorder[pstart]);
            int cur_loc = map[preorder[pstart]];
            int left_size = cur_loc - istart;
            TreeNode *root = new TreeNode(preorder[pstart]);
            root->left = dfs(pstart + 1, pstart + left_size, istart, cur_loc - 1);
            root->right = dfs(pstart + left_size + 1, pend, cur_loc + 1, iend);
            return root;
        };
        return dfs(0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
