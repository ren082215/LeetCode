class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res = asteroids;
        while (true) {
            if (res.size() <= 1) return res;
            vector<int> t{res[0]};
            for (int i = 1; i < res.size(); ++i) {
                if (t.empty() || (res[i] > 0 && t.back() < 0) || res[i] * t.back() > 0) {
                    t.push_back(res[i]);
                } else if (res[i] + t.back() == 0) {
                    t.pop_back();
                } else if (res[i] < 0 && res[i] + t.back() < 0) {
                     t.back() = res[i];
                }
            }
            if (t.size() == res.size()) break;
            else res = t;
        }
        return res;
    }
};
