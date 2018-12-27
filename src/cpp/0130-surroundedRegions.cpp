class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != 0 && i != m - 1 && j != 0 && j != n - 1) continue;
                if (board[i][j] != 'O') continue;
                board[i][j] = '$';
                queue<int> q{{i * n + j}};
                while (!q.empty()) {
                    int t = q.front(), x = t / n, y = t % n; q.pop();
                    if (x >= 1 && board[x - 1][y] == 'O') {board[x - 1][y] = '$'; q.push(t - n);}
                    if (x < m - 1 && board[x + 1][y] == 'O') {board[x + 1][y] = '$'; q.push(t + n);}
                    if (y >= 1 && board[x][y - 1] == 'O') {board[x][y - 1] = '$'; q.push(t - 1);}
                    if (y < n - 1 && board[x][y + 1] == 'O') {board[x][y + 1] = '$'; q.push(t + 1);}
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '$') board[i][j] = 'O';
            }
        }
    }
};
