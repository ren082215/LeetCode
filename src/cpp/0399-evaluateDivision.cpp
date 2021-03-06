class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> res;
        unordered_map<string, unordered_map<string, double>> g;
        for (int i = 0; i < equations.size(); ++i) {
            g[equations[i].first].emplace(equations[i].second, values[i]);
            g[equations[i].first].emplace(equations[i].first, 1.0);
            g[equations[i].second].emplace(equations[i].first, 1.0 / values[i]);
            g[equations[i].second].emplace(equations[i].second, 1.0);
        }
        for (auto query : queries) {
            if (!g.count(query.first) || !g.count(query.second)) {
                res.push_back(-1.0);
                continue;
            }
            queue<pair<string, double>> q;
            unordered_set<string> visited{query.first};
            bool found = false;
            q.push({query.first, 1.0});
            while (!q.empty() && !found) {
                for (int i = q.size(); i > 0; --i) {
                    auto t = q.front(); q.pop();
                    if (t.first == query.second) {
                        found = true;
                        res.push_back(t.second);
                        break;
                    }
                    for (auto a : g[t.first]) {
                        if (visited.count(a.first)) continue;
                        visited.insert(a.first);
                        a.second *= t.second;
                        q.push(a);
                    }
                }
            }
            if (!found) res.push_back(-1.0);
        }
        return res;
    }
};
