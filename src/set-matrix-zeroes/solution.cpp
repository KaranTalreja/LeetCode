class Solution {
  public:
    void setZeroes(vector<vector<int>>& matrix) {
      int rZ = -1, cZ = -1;
      int M = matrix.size();
      if (!M) return;
      int N = matrix[0].size();
      for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
          if (matrix[i][j] == 0) {
            rZ = i;
            cZ = j;
            break;
          }
        }
        if (rZ != -1) break;
      }
      if (rZ == -1) return;
      for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
          if (matrix[i][j] == 0) {
            matrix[rZ][j] = 0;
            matrix[i][cZ] = 0;
          }
        }
      }
      for (int i = 0; i < M; i++) {
        if (matrix[i][cZ] == 0 && i != rZ) {
          for(int j = 0; j < N; j++) {
            matrix[i][j] = 0;
          }
        }
      }
      for (int j = 0; j < N; j++) {
        if (matrix[rZ][j] == 0) {
          for(int i = 0; i < M; i++) {
            matrix[i][j] = 0;
          }
        }
      }
      for (int i = 0; i < N; i++) matrix[rZ][i] = 0;
      return;
    }
};
