class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int res = 0, n = S.size();
        unordered_set<string> pass, out;
        for (string word : words) {
            if (pass.count(word) || out.count(word)) {
                if (pass.count(word)) ++res; 
                continue;
            }
            int i = 0, j = 0, m = word.size();
            while (i < n && j < m) {
                if (word[j] == S[i]) ++j;
                ++i;
            }
            if (j == m) {++res; pass.insert(word);}
            else out.insert(word);
        }
        return res;
    }
};
