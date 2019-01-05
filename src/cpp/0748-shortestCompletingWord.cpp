class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        map<int, vector<string>> m;
        vector<char> chars;
        for (string word : words) {
            m[word.size()].push_back(word);
        }
        for (char c : licensePlate) {
            if (c >= 'a' && c <= 'z') chars.push_back(c);
            else if (c >= 'A' && c <= 'Z') chars.push_back(c + 32);
        }
        for (auto a : m) {
            if (a.first < chars.size()) continue;
            for (string word : a.second) {
                bool succ = true;
                unordered_map<char, int> freq;
                for (char c : word) ++freq[c];
                for (char c : chars) {
                    if (--freq[c] < 0) {succ = false; break;}
                }
                if (succ) return word;
            }
        }
        return "";
    }
};
