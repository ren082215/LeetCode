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
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        helper(root, 1, res);
        return res;
    }
    void helper(TreeNode* root, int depth, vector<int>& res) {
        if (depth > res.size()) res.push_back(root->val);
        else res[depth - 1] = max(res[depth - 1], root->val);
        if (root->left) helper(root->left, depth + 1, res);
        if (root->right) helper(root->right, depth + 1, res);
    }
};
