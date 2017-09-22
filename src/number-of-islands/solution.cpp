class Solution {
  public:
    bool isValid(int r, int c, int& rows, int& cols, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
      if (r < 0 || r >= rows || c < 0 || c >= cols) return false;
      if (grid[r][c] == '1' && visited[r][c] == false) {visited[r][c] = true; return true;}
      return false;
    }

    int numIslands(vector<vector<char>>& grid) {
      int retval = 0;
      int rows = grid.size();
      if (!rows) return retval;
      int cols = grid[0].size();
      vector<vector<bool>> visited(rows, vector<bool>(cols, false));
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          if (grid[i][j] == '1' && visited[i][j] == false) {
            retval++;
            queue<pair<int,int>> Q;
            Q.push(pair<int,int>(i,j));
            visited[i][j] = true;
            while (!Q.empty()) {
              int r = Q.front().first;
              int c = Q.front().second;
              Q.pop();
              if (isValid(r+1,c,rows,cols,grid,visited)) Q.push(pair<int,int>(r+1,c));
              if (isValid(r,c+1,rows,cols,grid,visited)) Q.push(pair<int,int>(r,c+1));
              if (isValid(r-1,c,rows,cols,grid,visited)) Q.push(pair<int,int>(r-1,c));
              if (isValid(r,c-1,rows,cols,grid,visited)) Q.push(pair<int,int>(r,c-1));
            }
          }
        }
      }
      return retval;
    }
};
