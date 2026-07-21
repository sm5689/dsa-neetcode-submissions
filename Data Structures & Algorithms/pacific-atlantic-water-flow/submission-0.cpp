class Solution {
public:
    bool isValid(int row, int col, vector<vector<int>>& heights) {
        return row>=0 && row<heights.size() && col>=0 && col<heights[0].size();
    }
    void dfs(int row, int col, vector<vector<bool>>& visited, vector<vector<int>>& heights) {
        visited[row][col] = true;

        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        for (int i = 0; i< 4; i++) {
            int newRow = row+dx[i];
            int newCol = col+dy[i];
            if (isValid(newRow, newCol, heights) && !visited[newRow][newCol] && heights[newRow][newCol] >= heights[row][col]) {
                dfs(newRow, newCol, visited, heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        vector<vector<bool>> pacificVisited(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlanticVisited(heights.size(), vector<bool>(heights[0].size(), false));

        for (int i = 0; i< heights[0].size(); i++) {
            dfs(0, i, pacificVisited, heights);
            dfs(heights.size()-1, i, atlanticVisited, heights);
        }

        for (int i = 0; i< heights.size(); i++) {
            dfs(i, 0, pacificVisited, heights);
            dfs(i, heights[0].size()-1, atlanticVisited, heights);
        }

        vector<vector<int>> waterFlow;

        for (int i = 0; i< heights.size(); i++) {
            for (int j = 0; j< heights[0].size(); j++) {
                if (pacificVisited[i][j] == true && atlanticVisited[i][j] == true) {
                    waterFlow.push_back({i, j});
                }
            }
        }
        return waterFlow;
    }
};
