class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int res = num, n = str.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(str[i], str[j]);
                res = max(res, stoi(str));
                swap(str[i], str[j]);
            }
        }
        return res;
    }
};
