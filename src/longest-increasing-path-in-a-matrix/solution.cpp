/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

class Solution {
  public:
    bool isValid(int r, int c, int& M, int& N, int& currVal, vector<vector<int>>& matrix) {
      if (r < 0 || r >= M || c < 0 || c >= N) return false;
      if (currVal >= matrix[r][c]) return false;
      return true;
    }

    int helper(vector<vector<int>>& matrix, vector<vector<int>>& DP, int i, int j, int &M, int &N) {
      if (DP[i][j] != INT_MIN) return DP[i][j];
      static vector<vector<int>> options = {{0,1},{0,-1},{1,0},{-1,0}};
      int retval = 0;
      for (auto o : options) {
        if (isValid(i+o[0], j+o[1], M, N, matrix[i][j], matrix)) {
          int rc = helper(matrix, DP, i+o[0], j+o[1], M, N);
          if (rc > retval) retval = rc;
        }
      }
      DP[i][j] = retval + 1;
      return DP[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
      int M = matrix.size();
      if (!M) return 0;
      int N = matrix[0].size();
      int retval = INT_MIN;
      vector<vector<int>> DP(M, vector<int>(N, INT_MIN));
      for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
          int rc = helper(matrix, DP, i, j, M, N);
          if (retval < rc) retval = rc;
        }
      }
      return retval;
    }
};

class Solution {
  public:

    bool isValid(int r , int c, int& row, int& col, int& curr, int level, vector<vector<int>>& matrix, vector<vector<int>>& DP) {
      if (r < 0 || r >= row || c < 0 || c >= col) return false;
      if (DP[r][c] >= level) return false;
      if (matrix[r][c] <= curr) return false;
      return true;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
      int row = matrix.size();
      if(!row) return 0;
      int col = matrix[0].size();
      vector<vector<int>> DP(row, vector<int>(col, INT_MIN));
      vector<vector<int>> moves = {{0,1},{1,0},{0,-1},{-1,0}};
      int retval = 0;
      for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
          if(DP[r][c] != INT_MIN) continue;
          queue<pair<int,int>> Q;
          Q.push(pair<int,int>(r,c));
          int level = 1;
          while(!Q.empty()) {
            int size = Q.size();
            if (retval < level) retval = level;
            for (int i = 0; i < size; i++) {
              pair<int,int> curr = Q.front();
              Q.pop();
              int r = curr.first;
              int c = curr.second;
              if (DP[r][c] < level) DP[r][c] = level;
              for (int j = 0; j < moves.size(); j++) {
                if (isValid(r+moves[j][0], c+moves[j][1], row, col, matrix[r][c], level+1, matrix, DP)) {
                  Q.push(pair<int,int>(r+moves[j][0], c +moves[j][1]));
                  if (DP[r + moves[j][0]][c+moves[j][1]] < level+1) DP[r+moves[j][0]][c+moves[j][1]] = level+1;
                }
              }
            }
            level++;
          }
        }
      }
      return retval;
    }
};
