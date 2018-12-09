#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <assert.h>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<int> pos(n, -1);
        totalNQueensDFS(pos, 0, res);
        return res;
    }
    void totalNQueensDFS(vector<int> &pos, int row, int &res) {
        int n = pos.size();
        if (row == n) ++res;
        else {
            for (int col = 0; col < n; ++col) {
                if (isValid(pos, row, col)) {
                    pos[row] = col;
                    totalNQueensDFS(pos, row + 1, res);
                    pos[row] = -1;
                }
            }
        }
    }
    bool isValid(vector<int> &pos, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (col == pos[i] || abs(row - i) == abs(col - pos[i])) {
                return false;
            }
        }
        return true;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().totalNQueens(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
