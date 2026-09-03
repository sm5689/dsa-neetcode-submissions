class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<int>>& visited) {
        visited[r][c] = 1;
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        for (int i = 0; i< 4; i++) {
            int row = r+dx[i];
            int col = c+dy[i];
            if (row >= 0 && row < board.size() && col >= 0 && col < board[0].size() && visited[row][col] == 0 && board[row][col] == 'O') {
                dfs(row, col, board, visited);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        for (int i = 0; i< cols; i++) {
            if (board[0][i] == 'O' && visited[0][i] == 0) {
                dfs(0, i, board, visited);
            }
            if (board[rows-1][i] == 'O' && visited[rows-1][i] == 0) {
                dfs(rows-1, i, board, visited);
            }
        }
        for (int i = 0; i< rows; i++) {
            if (board[i][0] == 'O' && visited[i][0] == 0) {
                dfs(i, 0, board, visited);
            }
            if (board[i][cols-1] == 'O' && visited[i][cols-1] == 0) {
                dfs(i, cols-1, board, visited);
            }
        }
        for (int i = 1; i< rows; i++) {
            for (int j = 1; j< cols; j++) {
                if (board[i][j] == 'O' && visited[i][j] == 0) board[i][j] = 'X';
            }
        }
    }
};
