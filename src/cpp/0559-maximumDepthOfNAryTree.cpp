/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        int res = 0;
        helper(root, 1, res);
        return res;
    }
    void helper(Node* node, int cur, int& res) {
        if (!node) return;
        if (node->children.empty()) res = max(res, cur);
        for (Node* child : node->children) {
            helper(child, cur + 1, res);
        }
    }
};
