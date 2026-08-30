class Solution {
public:
    bool checkValidRC(int row, int col, vector<string>& board) {
        int r = row;
        int c = col;
        while (r >= 0) {
            if (board[r][col] == 'Q') return false;
            r--;
        }
        r = row;
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r--, c--;
        }
        r = row, c = col;
        while (r >= 0 && c <= board.size()-1) {
            if (board[r][c] == 'Q') return false;
            r--, c++;
        }
        return true;
    }
    void solveNQueensHelper (vector<vector<string>>& ans, vector<string>& nQueens, int row) {
        if (row == nQueens.size()) {
            ans.push_back(nQueens);
            return;
        }
        for (int i = 0; i< nQueens.size(); i++) {
            if (checkValidRC(row, i, nQueens)) {
                nQueens[row][i] = 'Q';
                solveNQueensHelper(ans, nQueens, row+1);
                nQueens[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> nQueens;
        string s = "";
        for (int i = 0; i< n; i++) {
            s+= ".";
        }
        for (int i = 0; i< n; i++) {
            nQueens.push_back(s);
        }
        solveNQueensHelper(ans, nQueens, 0);
        return ans;
    }
};
