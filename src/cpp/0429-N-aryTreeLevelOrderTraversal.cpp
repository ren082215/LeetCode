class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<Node*> q{{root}};
        while (!q.empty()) {
            vector<int> out;
            for (int i = q.size(); i > 0; --i) {
                auto t = q.front(); q.pop();
                out.push_back(t->val);
                if (!t->children.empty()) {
                    for (auto a : t->children) q.push(a);
                }
            }
            res.push_back(out);
        }
        return res;
    }
};
