class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i = sqrt(c); i >= 0; --i) {
            if (i * i == c) return true;
            int d = c - i * i, t = sqrt(d);
            if (t * t == d) return true;
        }
        return false;
    }
};
