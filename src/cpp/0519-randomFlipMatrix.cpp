class Solution {
public:
    Solution(int n_rows, int n_cols) {
        row = n_rows; col = n_cols;
    }
    
    vector<int> flip() {
        while (true) {
            int val = rand() % (row * col);
            if (!flipped.count(val)) {
                flipped.insert(val);
                return {val / col, val % col};
            }
        }
    }
    
    void reset() {
        flipped.clear();
    }

private:
    int row, col;
    unordered_set<int> flipped;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj.flip();
 * obj.reset();
 */
