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
    vector<vector<string>> printTree(TreeNode* root) {
        int h = getHeight(root), w = pow(2, h) - 1;
        vector<vector<string>> res(h, vector<string>(w, ""));
        helper(root, 0, w - 1, 0, h, res);
        return res;
    }
    void helper(TreeNode* node, int i, int j, int curH, int height, vector<vector<string>>& res) {
        if (!node || curH == height) return;
        res[curH][(i + j) / 2] = to_string(node->val);
        helper(node->left, i, (i + j) / 2, curH + 1, height, res);
        helper(node->right, (i + j) / 2 + 1, j, curH + 1, height, res);
    }
    int getHeight(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }
};
