class Solution {
  public:
    long Util (vector<vector<int>>& grid, vector<vector<int>>&DP, int i, int j) {
      if(i >= DP.size() || j >= DP[i].size()) return INT_MAX;
      if (DP[i][j] == -1) {
        long down = Util(grid, DP, i+1, j);
        long right = Util(grid, DP, i, j+1);
        if (down != INT_MAX || right != INT_MAX)  DP[i][j] = min(down + grid[i][j],right + grid[i][j]);
        else DP[i][j] = grid[i][j];
      }
      return DP[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
      int row = grid.size();
      if (!row) return row;
      int col = grid[0].size();
      vector<vector<int>> minPathSum (row, vector<int>(col,-1));
      return Util(grid, minPathSum, 0, 0);
    }
};
