class Solution {
public:
    int uniquePathsHelper(int row, int col, int m, int n, vector<vector<int>>& dp) {
        bool valid = row >= 0 && row < m && col >= 0 && col < n;
        if (!valid) return 0;
        if (row == m-1 && col == n-1) return 1;
        if (dp[row][col] != -1) return dp[row][col];
        return dp[row][col] = uniquePathsHelper(row+1, col, m, n, dp)+uniquePathsHelper(row, col+1, m, n, dp);

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return uniquePathsHelper(0, 0, m, n, dp);
    }   
};
