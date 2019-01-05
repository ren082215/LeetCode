class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        TreeNode *p = root, *pre = NULL;
        stack<TreeNode*> s;
        int mx = 0, cnt = 1;;
        while (!s.empty() || p) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top(); s.pop();
            if (pre) {
                cnt = (p->val == pre->val) ? cnt + 1 : 1;
            }
            if (cnt >= mx) {
                if (cnt > mx) res.clear();
                res.push_back(p->val);
                mx = cnt;
            }
            pre = p;
            p = p->right;
        }
        return res;
    }
};
