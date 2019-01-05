class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        for (int i = L; i <= R; ++i) {
            int t = i, cnt = 0;
            while (t > 0) {
                if (t & 1 == 1) ++cnt;
                t >>= 1;
            }
            bool succ = true;
            for (int j = sqrt(cnt); j > 1; --j) {
                if (cnt % j == 0) {
                    succ = false; break;
                }
            }
            if (succ && cnt != 1) ++res;
        }
        return res;
    }
};
