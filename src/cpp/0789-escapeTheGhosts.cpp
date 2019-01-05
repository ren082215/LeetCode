class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dist = abs(target[0]) + abs(target[1]), mn = INT_MAX;
        for (auto ghost : ghosts) {
            int t = abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]);
            mn = min(mn, t);
        }
        return dist < mn;
    }
};
