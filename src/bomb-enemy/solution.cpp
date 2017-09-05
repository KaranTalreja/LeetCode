/*
Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
Note that you can only put the bomb at an empty cell.

Example:
For the given grid

0 E 0 0
E 0 W E
0 E 0 0

return 3. (Placing a bomb at (1,1) kills 3 enemies)
Credits:
Special thanks to @memoryless for adding this problem and creating all test cases.
*/
class Solution {
  public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
      int rows = grid.size();
      if (!rows) return 0;
      int cols = grid[0].size();
      int retval = 0;
      vector<vector<int>> enemyGrid(rows, vector<int>(cols,0));
      for (int r = 0; r < rows; r++) {
        int enemyH = 0;
        int enemyT = 0;
        for (int c = 0; c < cols; c++) {
          if (grid[r][c] == 'W') enemyH = 0;
          else if (grid[r][c] == 'E') enemyH++;
          else if (grid[r][c] == '0') enemyGrid[r][c] += enemyH;
          if (grid[r][cols-c-1] == 'W') enemyT = 0;
          else if (grid[r][cols-c-1] == 'E') enemyT++;
          else if (grid[r][cols-c-1] == '0') enemyGrid[r][cols-c-1] += enemyT;
        }
      }
      for (int c = 0; c < cols; c++) {
        int enemyH = 0;
        int enemyT = 0;
        for (int r = 0; r < rows; r++) {
          if (grid[r][c] == 'W') enemyH = 0;
          else if (grid[r][c] == 'E') enemyH++;
          else if (grid[r][c] == '0') enemyGrid[r][c] += enemyH;
          if (grid[rows-r-1][c] == 'W') enemyT = 0;
          else if (grid[rows-r-1][c] == 'E') enemyT++;
          else if (grid[rows-r-1][c] == '0') enemyGrid[rows-r-1][c] += enemyT;
        }
      }
      for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
          //cout << enemyGrid[r][c] << ",";
          if (retval < enemyGrid[r][c] && grid[r][c] == '0') retval = enemyGrid[r][c];
        }
        //cout << endl;
      }
      return retval;
    }
};
