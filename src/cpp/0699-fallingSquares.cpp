class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
        int n = positions.size(), cur = 0;
        vector<int> heights(n), res;
        for (int i = 0; i < n; ++i) {
            int len = positions[i].second, left = positions[i].first, right = left + len;
            heights[i] += len;
            for (int j = i + 1; j < n; ++j) {
                int l = positions[j].first, r = l + positions[j].second;
                if (l < right && r > left) {
                    heights[j] = max(heights[j], heights[i]);
                }
            }
        }
        for (int h : heights) {
            cur = max(cur, h);
            res.push_back(cur);
        }
        return res;
    }
};
