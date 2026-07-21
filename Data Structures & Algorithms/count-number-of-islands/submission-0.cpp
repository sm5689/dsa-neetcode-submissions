class Solution {
public:
bool checkValidIndex(int row, int col, vector<vector<char>> &grid) {
  if (row < grid.size() && row > -1 && col > -1 && col < grid[0].size()) {
    return true;
  }
  else {
    return false;
  }
}

void checkVisited(vector<vector<char>> &grid, int row, int col, vector<vector<bool>> &visited) {
  stack<pair<int, int>> st;
  st.push(make_pair(row, col));
  visited[row][col] = true;

  while (!st.empty()) {
    pair<int, int> front = st.top();
    st.pop();
    int r = front.first;
    int c = front.second;

    if (checkValidIndex(r, c+1, grid) && !visited[r][c+1] && grid[r][c+1] == '1') {
      st.push(make_pair(r, c+1));
      visited[r][c+1] = true;
    }

    if (checkValidIndex(r, c-1, grid) && !visited[r][c-1] && grid[r][c-1] == '1') {
      st.push(make_pair(r, c-1));
      visited[r][c-1] = true;
    }

    if (checkValidIndex(r-1, c, grid) && !visited[r-1][c] && grid[r-1][c] == '1') {
      st.push(make_pair(r-1, c));
      visited[r-1][c] = true;
    }

    if (checkValidIndex(r+1, c, grid) && !visited[r+1][c] && grid[r+1][c] == '1') {
      st.push(make_pair(r+1, c));
      visited[r+1][c] = true;
    }

  }
  
}
int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    for (int i = 0; i< grid.size(); i++) {
        for (int j = 0; j< grid[0].size(); j++) {
            if (grid[i][j] == '1' && visited[i][j] != true) {
            checkVisited(grid, i, j, visited);
            count++;
            }
        }
    }
    return count;
}
};
