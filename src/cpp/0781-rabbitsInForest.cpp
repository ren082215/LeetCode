class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        unordered_map<int, int> m;      
        for (int ans : answers) {
            if (!m.count(ans + 1) || m[ans + 1] == 0) {
                res += ans + 1;
                m[ans + 1] = ans;
            } else {
                --m[ans + 1];
            }
        }
        return res;
    }
};
