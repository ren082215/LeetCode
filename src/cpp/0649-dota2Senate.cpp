class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> q1, q2;
        for (int i = 0; i < n; ++i) {
            (senate[i] == 'R') ? q1.push(i) : q2.push(i);
        }
        while (!q1.empty() && !q2.empty()) {
            int i = q1.front(); q1.pop();
            int j = q2.front(); q2.pop();
            (i < j) ? q1.push(i + n) : q2.push(j + n);
        }
        return (q1.size() > q2.size()) ? "Radiant" : "Dire";
    }
};
