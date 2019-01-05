class Solution {
public:
    string customSortString(string S, string T) {
        string res = "";
        unordered_map<char, int> m;
        for (char c : T) ++m[c];
        for (char c : S) {
            res += string(m[c], c);
            m[c] = 0;
        }
        for (auto a : m) {
            res += string(a.second, a.first);
        }
        return res;
    }
};
