class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int mx = 0;
        unordered_map<int, int> m;
        for (auto a : wall) {
            int sum = 0;
            for (int i = 0; i < a.size() - 1; ++i) {
                sum += a[i];
                ++m[sum];
                mx = max(mx, m[sum]);
            }
        }
        return wall.size() - mx;
    }
};
