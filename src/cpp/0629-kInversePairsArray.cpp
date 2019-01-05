class Solution {
public:
    int kInversePairs(int n, int k) {
        int M = 1000000007;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (int m = 0; m <= k; ++m) {
                    if (m - j >= 0 && m - j <= k) {
                        dp[i][m] = (dp[i][m] + dp[i - 1][m - j]) % M;
                    }
                }
            }
        }
        return dp[n][k];
    }
};
