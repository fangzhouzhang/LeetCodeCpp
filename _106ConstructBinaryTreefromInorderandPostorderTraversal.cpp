//
// Created by Fangzhou Zhang on 2020/4/12.
//
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        function<TreeNode*(int, int, int, int)> dfs = [&](int s1, int e1, int s2, int e2){
            if (s1 > e1) return (TreeNode*)NULL;
            if (s1 == e1) return new TreeNode(postorder[s1]);
            TreeNode *root = new TreeNode(postorder[e1]);
            int cur_loc = map[postorder[e1]];
            int right_size = e2 - cur_loc;
            root->left = dfs(s1, e1 - right_size - 1, s2, cur_loc - 1);
            root->right = dfs(e1 - right_size, e1 - 1, cur_loc + 1, e2);
            return root;
        };
        return dfs(0, postorder.size() - 1, 0, inorder.size() - 1);
    }
};
