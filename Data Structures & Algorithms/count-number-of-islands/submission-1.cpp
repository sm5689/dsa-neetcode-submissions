class Solution {
public:
    void bfsHelper(int row, int col, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = true;
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i< 4; i++) {
                if (row+dx[i] >= 0 && col+dy[i] >= 0 
                    && row+dx[i] < grid.size() 
                    && col+dy[i] < grid[0].size() 
                    && grid[row+dx[i]][col+dy[i]] == '1' 
                    && visited[row+dx[i]][col+dy[i]] != true) {
                    q.push({row+dx[i], col+dy[i]});
                    visited[row+dx[i]][col+dy[i]] = true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int totalIslands = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0; i< grid.size(); i++) {
            for (int j = 0; j< grid[0].size(); j++) {
                if (grid[i][j] == '1' && visited[i][j] != true) {
                    bfsHelper(i, j, visited, grid);
                    totalIslands++;
                }
            }
        }
        return totalIslands;
    }
};
