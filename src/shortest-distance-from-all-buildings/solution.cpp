/*
You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.

Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.
*/
class Solution {
  public:
    void getBuildings(vector<vector<int>>& grid, vector<pair<int,int>>& buildings) {
      int rows = grid.size();
      int cols = grid[0].size();
      for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
          if (grid[r][c] == 1) buildings.push_back(pair<int,int>(r,c));
        }
      }
    }

    bool isValid(int r, int c, int& rows, int& cols, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
      if (r < 0 || c < 0 || r >= rows || c >= cols) return false;
      if (visited[r][c] == false && (grid[r][c] != 2 && grid[r][c] != 1)) return true;
      return false; 
    }

    void updateDP (vector<vector<int>>& grid, vector<vector<long>>& DP, pair<int,int>& building, vector<vector<int>>& vistedBy) {
      int rows = grid.size();
      int cols = grid[0].size();
      vector<vector<bool>> visited(rows, vector<bool>(cols,false));
      queue<pair<int,int>> Q;
      Q.push(building);
      visited[building.first][building.second] = true;
      int level = 0;
      while (!Q.empty()) {
        int size = Q.size();
        for (int i = 0; i < size; i++) {
          pair<int, int> curr = Q.front();
          Q.pop();
          int r = curr.first, c = curr.second;
          if (DP[r][c] != INT_MAX) DP[r][c] += level;
          else DP[r][c] = level;
          if (isValid(r+1, c, rows, cols, grid, visited)) { Q.push(pair<int,int>(r+1, c)); visited[r+1][c] = true;}
          if (isValid(r, c+1, rows, cols, grid, visited)) { Q.push(pair<int,int>(r, c+1)); visited[r][c+1] = true;}
          if (isValid(r-1, c, rows, cols, grid, visited)) { Q.push(pair<int,int>(r-1, c)); visited[r-1][c] = true;}
          if (isValid(r, c-1, rows, cols, grid, visited)) { Q.push(pair<int,int>(r, c-1)); visited[r][c-1] = true;}
        }
        level++;
      }
      for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
          vistedBy[r][c] += (visited[r][c] == true && grid[r][c] == 0) ? 1 : 0; 
        }
      }
    }

    int shortestDistance(vector<vector<int>>& grid) {
      int rows = grid.size();
      if (!rows) return -1;
      int cols = grid[0].size();
      vector<pair<int,int>> buildings;
      getBuildings(grid, buildings);
      vector<vector<long>> DP(rows, vector<long>(cols, INT_MAX));
      vector<vector<int>> visitedBy(rows, vector<int>(cols, 0));
      for (int i = 0; i < buildings.size(); i++) {
        updateDP(grid, DP, buildings[i], visitedBy);
      }
      long retval = INT_MAX;
      for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
          if (DP[r][c] < retval && grid[r][c] == 0 && visitedBy[r][c] == buildings.size()) retval = DP[r][c];
        }
      }
      return retval == INT_MAX ? -1 : retval;
    }
};
