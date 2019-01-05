class Solution {
public:
    bool judgeCircle(string moves) {
        int cnt1 = 0, cnt2 = 0;
        for (char move : moves) {
            if (move == 'U') ++cnt1;
            else if (move == 'D') --cnt1;
            else if (move == 'L') ++cnt2;
            else if (move == 'R') --cnt2;
        }
        return cnt1 == 0 && cnt2 == 0;
    }
};
