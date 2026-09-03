class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i< rows; i++) {
            for (int j = 0; j< cols; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                if (grid[i][j] == 1) fresh++;
            }
        }
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        int time = 0;
        while (!q.empty()) {
            int qSize = q.size();
            bool rotted = false;
            for (int j = 0; j< qSize; j++) {
                pair<int, int> front = q.front();
                q.pop();
                int x = front.first;
                int y = front.second;
                for (int i = 0; i< 4; i++) {
                    int newX = x+dx[i];
                    int newY = y+dy[i];
                    if (newX >= 0 && newX < rows
                        && newY >= 0 && newY < cols
                        && grid[newX][newY] == 1) {
                            grid[newX][newY] = 2;
                            q.push({newX, newY});
                            fresh--;
                            rotted = true;
                    }
                }
            }
            if (rotted) time++;
        }
        return fresh==0?time:-1;
    }
};
