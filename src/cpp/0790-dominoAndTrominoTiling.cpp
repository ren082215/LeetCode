class Solution {
public:
    int numTilings(int N) {
        int M = 1e9 + 7;
        vector<long> dp(N + 1);
        dp[0] = 1; dp[1] = 1; dp[2] = 2;
        for (int i = 3; i <= N; ++i) {
            dp[i] = (dp[i - 1] * 2 + dp[i - 3]) % M;
        }
        return dp[N];
    }
};
