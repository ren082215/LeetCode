class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size(), max_idx = 0, res = 0;
        int m[128] = {0};
        bool ok = true;
        for (char c : s) ++m[c];
        for (int i = 0; i < n; ++i) {
            if (m[s[i]] < k) {
                res = max(res, longestSubstring(s.substr(max_idx, i - max_idx), k));
                ok = false;
                max_idx = i + 1;
            }
        }
        return ok ? n : max(res, longestSubstring(s.substr(max_idx, n - max_idx), k));
    }
};
