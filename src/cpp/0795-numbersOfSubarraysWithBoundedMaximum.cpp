class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int res = 0, n = A.size();
        for (int i = 0; i < n; ++i) {
            if (A[i] > R) continue;
            int curMax = INT_MIN;
            for (int j = i; j < n; ++j) {
                curMax = max(curMax, A[j]);
                if (curMax > R) break;
                if (curMax >= L) ++res;
            }
        }
        return res;
    }
};
