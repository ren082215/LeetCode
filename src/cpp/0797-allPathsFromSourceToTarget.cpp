class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        helper(graph, 0, {}, res);
        return res;
    }
    void helper(vector<vector<int>>& graph, int cur, vector<int> path, vector<vector<int>>& res) {
        path.push_back(cur);
        if (cur == graph.size() - 1) res.push_back(path);
        else for (int neigh : graph[cur]) helper(graph, neigh, path, res);
    }
};
