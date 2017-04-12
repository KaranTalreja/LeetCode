class Solution {
  public:
    bool checkIdx (int i, int j, int rows, int cols) {
      if (i > rows || j > cols || i < 0 || j < 0) return false;
      return true;
    }

    int helper(vector<vector<int>>& dungeon, vector<vector<int>>& dp, int i, int j, int rows, int cols) {
      if (i == rows && j == cols) return max(1,1-dungeon[i][j]);
      else if (dp[i][j] != 0) return dp[i][j];
      bool right = checkIdx(i, j+1, rows, cols), down = checkIdx(i+1, j, rows, cols);
      if (right == true && down == true)
        dp[i][j] = min(max(1,helper(dungeon, dp, i, j+1, rows, cols) - dungeon[i][j]),max(1,helper(dungeon, dp, i+1, j, rows, cols) - dungeon[i][j]));
      else if (right == true)
        dp[i][j] = max(1,helper(dungeon, dp, i, j+1, rows, cols) - dungeon[i][j]);
      else
        dp[i][j] = max(1,helper(dungeon, dp, i+1, j, rows, cols) - dungeon[i][j]);
      return dp[i][j];
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
      int rows = dungeon.size();
      if (!rows) return INT_MAX;
      int cols = dungeon[0].size();
      vector<vector<int>> dp = vector<vector<int>>(rows, vector<int>(cols, 0));
      return helper(dungeon, dp, 0, 0, rows-1, cols-1);
    }
};
