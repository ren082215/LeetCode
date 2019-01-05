class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int x = 0, n = nums.size();
        for (int num : nums) x ^= num;
        return x == 0 || n % 2 == 0;
    }
};
