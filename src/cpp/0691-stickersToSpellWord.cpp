class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = target.size(), m = 1 << n;
        vector<int> dp(m, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < m; ++i) {
            if (dp[i] == INT_MAX) continue;
            for (string &sticker : stickers) {
                int cur = i;
                for (char c : sticker) {
                    for (int k = 0; k < n; ++k) {
                        if (target[k] == c && !((cur >> k) & 1)) {
                            cur |= 1 << k;
                            break;
                        }
                    }
                }
                dp[cur] = min(dp[cur], dp[i] + 1);
            }
        }
        return dp[m - 1] == INT_MAX ? -1 : dp[m - 1];
    }
};
