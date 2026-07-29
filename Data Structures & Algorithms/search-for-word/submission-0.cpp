class Solution {
public:
    bool isValidIndex(int row, int col, vector<vector<char>>& board) {
        return row >= 0 && row < board.size() && col >= 0 && col < board[0].size() && board[row][col] != '#';
    }
    bool existHelper(int index, int row, int col, vector<vector<char>>& board, string word) {
        if (!isValidIndex(row, col, board)) return false;
        if (board[row][col] != word[index]) return false;
        if (index == word.length()-1) {
            if (board[row][col] == word[index]) return true;
        }
        char original = board[row][col];
        board[row][col] = '#';
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        bool ans = false;
        for (int i = 0; i< 4; i++) {
            if(existHelper(index+1, row+dx[i], col+dy[i], board, word)) ans = true;;
        }
        board[row][col] = original;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j< board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if(existHelper(0, i, j, board, word)) return true;
                }
            }
        }
        return false;
    }
};
