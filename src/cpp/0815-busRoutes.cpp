class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        map<int, vector<int>> stops;
        for (int i = 0; i < routes.size(); i++) {
            for (auto n : routes[i]) stops[n].push_back(i);
        }
        
        int ans = 0;
        queue<int> que;
        que.push(S);
        set<int> visitedStop;
        set<int> visitedBus;
        while (!que.empty()) {
            int size = que.size();
            set<int> tmp;
            for (int i = 0; i < size; i++) {
                int cur = que.front();
                que.pop();
                if (cur == T) return ans;
                if (visitedStop.count(cur)) continue;
                visitedStop.emplace(cur);
                
                for (auto bus : stops[cur]) {
                    if (visitedBus.count(bus)) continue;
                    visitedBus.emplace(bus);
                    for (auto stop : routes[bus])
                        tmp.emplace(stop);
                }
            }
            for (auto s : tmp) que.push(s);
            ans++;
        }
        
        return -1;
    }
};
