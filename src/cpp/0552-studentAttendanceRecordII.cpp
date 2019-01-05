class Solution {
public:
    int checkRecord(int n) {
        int M = 1000000007;
        vector<int> P(n), L(n), A(n);
        P[0] = 1; L[0] = 1; L[1] = 3;
        A[0] = 1; A[1] = 2; A[2] = 4;
        for (int i = 1; i < n; ++i) {
            P[i] = ((P[i - 1] + L[i - 1]) % M + A[i - 1]) % M;
            if (i > 1) L[i] = ((A[i - 1] + P[i - 1]) % M + (A[i - 2] + P[i - 2]) % M) % M;
            if (i > 2) A[i] = ((A[i - 1] + A[i - 2]) % M + A[i - 3]) % M;
        }
        return ((A[n - 1] + P[n - 1]) % M + L[n - 1]) % M;
    }
};
