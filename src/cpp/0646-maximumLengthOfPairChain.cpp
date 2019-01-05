class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        stack<vector<int>> st;
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        for (auto pair : pairs) {
            if (st.empty()) st.push(pair);
            else {
                auto t = st.top();
                if (pair[0] > t[1]) st.push(pair);
            }
        }
        return st.size();
    }
};
