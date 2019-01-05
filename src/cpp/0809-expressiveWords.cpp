class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int res = 0, m = S.size(), n = words.size();
        for (string word : words) {
            int i = 0, j = 0;
            for (; i < m; ++i) {
                if (j < word.size() && S[i] == word[j]) ++j;
                else if (i > 0 && S[i] == S[i - 1] && i + 1 < m && S[i] == S[i + 1]) ++i;
                else if (!(i > 1 && S[i] == S[i - 1] && S[i] == S[i - 2])) break;
            }
            if (i == m && j == word.size()) ++res;
        }
        return res;
    }
};
