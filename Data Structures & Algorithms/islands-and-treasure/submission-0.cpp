class Solution {
public:
    
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        // push all 0 indices in the queue to initialize the bfs
        for (int i = 0; i< rows; i++) {
            for (int j = 0; j< cols; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int x = front.first;
            int y = front.second;
            for (int i = 0; i< 4; i++) {
                int newX = x+dx[i];
                int newY = y+dy[i];
                if (newX >= 0 && newX < rows 
                    && newY >= 0 && newY < cols 
                    && grid[newX][newY] != -1) {
                        int newDist = grid[x][y]+1;
                        if (grid[newX][newY] > newDist) {
                            grid[newX][newY] = newDist;
                            q.push({newX, newY});
                        }
                }
            }
        }
    }
};
