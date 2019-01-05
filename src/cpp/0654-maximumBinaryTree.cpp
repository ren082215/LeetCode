/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return NULL;
        int mx = INT_MIN, mx_idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (mx < nums[i]) {
                mx = nums[i];
                mx_idx = i;
            }
        }
        TreeNode *node = new TreeNode(mx);
        vector<int> leftArr = vector<int>(nums.begin(), nums.begin() + mx_idx);
        vector<int> rightArr = vector<int>(nums.begin() + mx_idx + 1, nums.end());
        node->left = constructMaximumBinaryTree(leftArr);
        node->right = constructMaximumBinaryTree(rightArr);
        return node;
    }
};
