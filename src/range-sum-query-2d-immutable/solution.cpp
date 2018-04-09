class NumMatrix {
  public:
    vector<vector<int>> DP;
    int helper (int i, int j, int& R, int& C) {
      if (i < 0 || i >= R || j < 0 || j >= C) return 0;
      return DP[i][j];
    }

    NumMatrix(vector<vector<int>> matrix) : DP(matrix) {
      int R = matrix.size();
      if (R > 0) {
        int C = matrix[0].size();
        for (int i = 0; i < R; i++) {
          for (int j = 0; j < C; j++) {
            DP[i][j] += helper(i-1, j, R, C) + helper(i, j-1, R, C) - helper(i-1, j-1, R, C);
          }
        }
      }
      // for (auto R : DP) {
      //     for (auto C : R) {
      //         cout << C << " ";
      //     }
      //     cout << endl;
      // }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
      int R = DP.size();
      if (!R) return 0;
      int C = DP[0].size();
      return helper(row2, col2, R, C) - helper(row1-1, col2, R, C) - helper(row2, col1-1, R, C) + helper(row1-1, col1-1, R, C);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
