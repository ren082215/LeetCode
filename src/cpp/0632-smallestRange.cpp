class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> res;
        vector<pair<int, int>> v;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            for (int num : nums[i]) {
                v.push_back({num, i});
            }
        }
        sort(v.begin(), v.end());
        int left = 0, n = v.size(), k = nums.size(), cnt = 0, diff = INT_MAX;
        for (int right = 0; right < n; ++right) {
            if (m[v[right].second] == 0) ++cnt;
            ++m[v[right].second];
            while (cnt == k && left <= right) {
                if (diff > v[right].first - v[left].first) {
                    diff = v[right].first - v[left].first;
                    res = {v[left].first, v[right].first};
                } 
                if (--m[v[left].second] == 0) --cnt;
                ++left;
            }
        }
        return res;
    }
};
