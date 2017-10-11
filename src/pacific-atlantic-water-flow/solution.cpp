/*
Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:
The order of returned grid coordinates does not matter.
Both m and n are less than 150.
Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
*/
class Solution {
  public:
    bool isValid (int r, int c, int& rows, int& cols, vector<vector<int>>& matrix, int parentHeight) {
      if (r < 0 || c < 0 || r >= rows || c >= cols) return false;
      if (matrix[r][c] < parentHeight) return false;
      return true;
    }

    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
      int rows = matrix.size();
      vector<pair<int,int>> retval;
      if (!rows) return retval;
      int cols = matrix[0].size();
      static vector<vector<int>> options = {{1,0},{0,1},{-1,0},{0,-1}};
      vector<pair<int,int>> pacificSource;
      vector<pair<int,int>> atlanticSource;
      for (int r = -1; r <= rows; r++) {
        pacificSource.push_back(pair<int,int>(r,-1));
        atlanticSource.push_back(pair<int,int>(r,cols));
      }
      for (int c = -1; c <= cols; c++) {
        atlanticSource.push_back(pair<int,int>(rows,c));
        pacificSource.push_back(pair<int,int>(-1,c));
      }
      vector<vector<bool>> visitedP(rows, vector<bool>(cols, false));
      for (int p = 0; p < pacificSource.size(); p++) {
        queue<pair<int,int>> Q;
        Q.push(pacificSource[p]);
        while (!Q.empty()) {
          pair<int,int> curr = Q.front();
          Q.pop();
          for (int i = 0; i < options.size(); i++) {
            int rNew = curr.first+options[i][0];
            int cNew = curr.second+options[i][1];
            int currHeight = 0;
            int r = curr.first;
            int c = curr.second;
            if (r < 0 || c < 0 || r >= rows || c >= cols) currHeight = 0;
            else currHeight = matrix[r][c]; 
            if (isValid(rNew, cNew, rows, cols, matrix, currHeight) && visitedP[rNew][cNew] == false) {
              visitedP[rNew][cNew] = true;
              Q.push(pair<int,int>(rNew, cNew));
            }
          }
        }
      }
      vector<vector<bool>> visitedA(rows, vector<bool>(cols, false));
      for (int p = 0; p < atlanticSource.size(); p++) {
        queue<pair<int,int>> Q;
        Q.push(atlanticSource[p]);
        while (!Q.empty()) {
          pair<int,int> curr = Q.front();
          Q.pop();
          for (int i = 0; i < options.size(); i++) {
            int rNew = curr.first+options[i][0];
            int cNew = curr.second+options[i][1];
            int currHeight = 0;
            int r = curr.first;
            int c = curr.second;
            if (r < 0 || c < 0 || r >= rows || c >= cols) currHeight = 0;
            else currHeight = matrix[r][c]; 
            if (isValid(rNew, cNew, rows, cols, matrix, currHeight) && visitedA[rNew][cNew] == false) {
              visitedA[rNew][cNew] = true;
              Q.push(pair<int,int>(rNew, cNew));
            }
          }
        }
      }
      for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
          if (visitedP[r][c] == true && visitedA[r][c] == true) {
            retval.push_back(pair<int,int>(r,c));
          }
        }
      }
      return retval;
    }
};
