class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        int size = min(k, int(nums1.size() * nums2.size()));
        vector<int> idx(nums1.size(), 0);
        for (int t = 0; t < size; ++t) {
            int cur = 0, sum = INT_MAX;
            for (int i = 0; i < nums1.size(); ++i) {
                if (idx[i] < nums2.size() && sum >= nums1[i] + nums2[idx[i]]) {
                    cur = i;
                    sum = nums1[i] + nums2[idx[i]];
                }
            }
            res.push_back({nums1[cur], nums2[idx[cur]]});
            ++idx[cur];
        }
        return res;
    }
};
