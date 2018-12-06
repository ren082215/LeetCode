class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > res;
        vector<int> out;
        sort(num.begin(), num.end());
        combinationSum2DFS(num, target, 0, out, res);
        return res;
    }
    void combinationSum2DFS(vector<int> &num, int target, int start, vector<int> &out, vector<vector<int> > &res) {
        if (target < 0) return;
        else if (target == 0) res.push_back(out);
        else {
            for (int i = start; i < num.size(); ++i) {
                if (i > start && num[i] == num[i - 1]) continue;
                out.push_back(num[i]);
                combinationSum2DFS(num, target - num[i], i + 1, out, res);
                out.pop_back();
            }
        }
    }
};
