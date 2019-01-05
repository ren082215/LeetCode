class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        vector<double> sums(n + 1);
        vector<vector<double>> dp(n, vector<double>(K));
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + A[i];
        }
        for (int i = 0; i < n; ++i) {
            dp[i][0] = (sums[n] - sums[i]) / (n - i);
        }    
        for (int k = 1; k < K; ++k) {
            for (int i = 0; i < n - 1; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    dp[i][k] = max(dp[i][k], (sums[j] - sums[i]) / (j - i) + dp[j][k - 1]);
                }
            }
        }
        return dp[0][K - 1];
    }
};
