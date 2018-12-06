class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        combinationSumDFS(candidates, target, 0, {}, res);
        return res;
    }
    void combinationSumDFS(vector<int> &candidates, int target, int start, vector<int> out, vector<vector<int>> &res) {
        if (target < 0) return;
        else if (target == 0) {res.push_back(out); return;}
        for (int i = start; i < candidates.size(); ++i) {
            out.push_back(candidates[i]);
            combinationSumDFS(candidates, target - candidates[i], i, out, res);
            out.pop_back();
        }
    }
};
