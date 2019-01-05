class Solution {
public:
    int findIntegers(int num) {
        int cnt = 0, n = num;
        string t = "";
        while (n > 0) {
            ++cnt;
            t += (n & 1) ? "1" : "0"; 
            n >>= 1;
        }
        vector<int> zero(cnt), one(cnt);
        zero[0] = 1; one[0] = 1;
        for (int i = 1; i < cnt; ++i) {
            zero[i] = zero[i - 1] + one[i - 1];
            one[i] = zero[i - 1];
        }
        int res = zero[cnt - 1] + one[cnt - 1];
        for (int i = cnt - 2; i >= 0; --i) {
            if (t[i] == '1' && t[i + 1] == '1') break;
            if (t[i] == '0' && t[i + 1] == '0') res -= one[i];
        }
        return res;
    }
};
