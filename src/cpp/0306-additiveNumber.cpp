// Non-recursion
class Solution {
public:
    bool isAdditiveNumber(string num) {
        for (int i = 1; i < num.size(); ++i) {
            for (int j = i + 1; j < num.size(); ++j) {
                string s1 = num.substr(0, i);
                string s2 = num.substr(i, j - i);
                long long d1 = atoll(s1.c_str()), d2 = atoll(s2.c_str());
                if ((s1.size() > 1 && s1[0] == '0') || (s2.size() > 1 && s2[0] == '0')) continue;
                long long next = d1 + d2;
                string nexts = to_string(next);
                string now = s1 + s2 + nexts;
                while (now.size() < num.size()) {
                    d1 = d2;
                    d2 = next;
                    next = d1 + d2;
                    nexts = to_string(next);
                    now += nexts;
                }
                if (now == num) return true;
            }
        }
        return false;
    }
};
