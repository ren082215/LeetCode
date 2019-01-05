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
    unordered_map<TreeNode*, int> m;
    int findTilt(TreeNode* root) {
        if (!root) return 0;
        int tilt = abs(getSum(root->left, m) - getSum(root->right, m));
        return tilt + findTilt(root->left) + findTilt(root->right);
    }
    int getSum(TreeNode* node, unordered_map<TreeNode*, int>& m) {
        if (!node) return 0;
        if (m.count(node)) return m[node];
        return m[node] = getSum(node->left, m) + getSum(node->right, m) + node->val;
    }
};
