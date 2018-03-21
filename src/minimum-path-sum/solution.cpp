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

class Solution {
  public:
    bool valid (int i, int j, int& R, int & C) {
      if (i < 0 || i >= R || j < 0 || j >= C) return false;
      return true;
    }

    long helper(vector<vector<int>>& grid, vector<vector<long>>& DP, int i , int j , int& R, int& C) {
      if (i == R-1 && j == C-1) return DP[i][j];
      if (DP[i][j] != INT_MAX) return DP[i][j];
      long rc1 = INT_MAX;
      if (valid(i+1, j, R, C)) rc1 = helper(grid, DP, i+1, j, R, C);
      long rc2 = INT_MAX;
      if (valid(i, j+1, R, C)) rc2 = helper(grid, DP, i, j+1, R, C);
      DP[i][j] = min(rc1, rc2) + grid[i][j];
      return DP[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
      int R = grid.size();
      if (!R) return 0;
      int C = grid[0].size();
      vector<vector<long>> DP(R, vector<long>(C, INT_MAX));
      DP[R-1][C-1] = grid[R-1][C-1];
      return helper(grid, DP, 0, 0, R, C);
    }
};
