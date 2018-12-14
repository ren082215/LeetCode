// Two binary search
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        if (target < matrix[0][0] || target > matrix.back().back()) return false;
        int left = 0, right = matrix.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] < target) left = mid + 1;
            else right = mid - 1;
        }
        int tmp = right;
        left = 0;
        right = matrix[tmp].size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[tmp][mid] == target) return true;
            else if (matrix[tmp][mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};
