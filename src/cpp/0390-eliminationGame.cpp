class Solution {
public:
    int lastRemaining(int n) {
        return help(n, true);    
    }
    int help(int n, bool left2right) {
        if (n == 1) return 1;
        if (left2right) {
            return 2 * help(n / 2, false);
        } else {
            return 2 * help(n / 2, true) - 1 + n % 2;
        }
    }
};
