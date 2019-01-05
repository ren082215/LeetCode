class Solution {
public:
    int preimageSizeFZF(int K) {
        long left = 0, right = 5L * (K + 1);
        while (left < right) {
            long mid = left + (right - left) / 2;
            long cnt = numOfTrailingZeros(mid);
            if (cnt == K) return 5;
            else if (cnt < K) left = mid + 1;
            else right = mid;
        }
        return 0;
    }
    long numOfTrailingZeros(long x) {
        long res = 0;
        for (; x > 0; x /= 5) {
            res += x / 5;
        }
        return res;
    }
};
