class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (bank.empty()) return -1;
        bank.push_back(start);
        int res = 0, n = bank.size();
        queue<int> q{{n - 1}};
        vector<vector<int>> dist(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                dist[i][j] = count(bank[i], bank[j]);
            }
        }
        unordered_set<int> visited;
        while (!q.empty()) {
            int len = q.size();
            ++res;
            for (int i = 0; i < len; ++i) {
                int t = q.front(); q.pop();
                visited.insert(t);
                for (int j = 0; j < n; ++j) {
                    if ((dist[t][j] != 1 && dist[j][t] != 1) || visited.count(j)) continue;
                    if (bank[j] == end) return res;
                    q.push(j);
                }
            }
        }
        return -1;
    }
    int count(string word1, string word2) {
        int cnt = 0, n = word1.size();
        for (int i = 0; i < n; ++i) {
            if (word1[i] != word2[i]) ++cnt;
        }
        return cnt;
    }
};
