class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        for (char s : S) {
            for (char j : J) {
                if (s == j) {
                    ++res; break;
                }
            }
        }
        return res;
    }
};
