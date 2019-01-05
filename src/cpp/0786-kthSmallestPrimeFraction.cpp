class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        priority_queue<pair<double, pair<int, int>>> q;
        for (int i = 0; i < A.size(); ++i) {
            q.push({-1.0 * A[i] / A.back(), {i, A.size() - 1}});
        }
        while (--K) {
            auto t = q.top().second; q.pop();
            --t.second;
            q.push({-1.0 * A[t.first] / A[t.second], {t.first, t.second}});
        }
        return {A[q.top().second.first], A[q.top().second.second]};
    }
};
