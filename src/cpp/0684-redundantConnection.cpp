class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> m;
        for (auto edge : edges) {
            if (hasCycle(edge[0], edge[1], m, -1)) return edge;
            m[edge[0]].insert(edge[1]);
            m[edge[1]].insert(edge[0]);
        }
        return {};
    }
    bool hasCycle(int cur, int target, unordered_map<int, unordered_set<int>>& m, int pre) {
        if (m[cur].count(target)) return true;
        for (int num : m[cur]) {
            if (num == pre) continue;
            if (hasCycle(num, target, m, cur)) return true;
        }
        return false;
    }
};
