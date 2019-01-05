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
    int widthOfBinaryTree(TreeNode* root) {
        int res = 0;
        vector<int> start;
        helper(root, 0, 1, start, res);
        return res;
    }
    void helper(TreeNode* node, int h, int idx, vector<int>& start, int& res) {
        if (!node) return;
        if (h >= start.size()) start.push_back(idx);
        res = max(res, idx - start[h] + 1);
        helper(node->left, h + 1, idx * 2, start, res);
        helper(node->right, h + 1, idx * 2 + 1, start, res);
    }
};
