class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), res = INT_MIN;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (visited[nums[i]]) continue;
            int cnt = 0, j = i;
            while(cnt == 0 || j != i) {
                visited[j] = true;
                j = nums[j];
                ++cnt;
            }
            res = max(res, cnt);
        }
        return res;
    }
};
