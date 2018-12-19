class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // O(nlogn)
        vector<vector<int>> vanss;  
        vector<int> ans;
        vector<bool> mark(nums.size(), false);  // if (mark[i]) nums[i] is in ans;
        bt(nums, vanss, ans, 0, mark);
        return vanss;
    }
private:
    void bt(vector<int>& nums, vector<vector<int>>& anss, vector<int>& ans, int start, vector<bool> &mark){
        if(start >= nums.size()){
            anss.push_back(ans);
            return ;
        }
        bt(nums,anss, ans, start + 1, mark);  // dont put nums[start] in ans
        if(start == 0 || nums[start - 1] != nums[start] || mark[start - 1]){
            ans.push_back(nums[start]);
            mark[start] = true;
            bt(nums,anss, ans, start + 1, mark);  // put nums[start] in ans
            ans.pop_back();
            mark[start] = false;
        }
    }
};
