class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        unordered_map<int, int> m;
        for (string word : words) {
            int mask = 0;
            for (char c : word) {
                mask |= 1 << (c - 'a');
            }
            m[mask] = max(m[mask], int(word.size()));
            for (auto a : m) {
                if (!(mask & a.first)) {
                    res = max(res, (int)word.size() * a.second);
                }
            }
        }
        return res;
    }
};
