class Solution {
  public:
    void transpose (vector<vector<int>>& matrix) {
      int rows = matrix.size();
      if (!rows) return;
      int cols = matrix[0].size();
      for (int r = 0; r < rows; r++) {
        for (int c = r; c < cols; c++) {
          int temp = matrix[r][c];
          matrix[r][c] = matrix[c][r];
          matrix[c][r] = temp;
        }
      }
    }

    void reverseRows(vector<vector<int>>& matrix) {
      int rows = matrix.size();
      if (!rows) return;
      int cols = matrix[0].size();
      for (int r = 0; r < rows; r++) {
        int p = 0; int q = cols-1;
        while (p < q) {
          int temp = matrix[r][p];
          matrix[r][p] = matrix[r][q];
          matrix[r][q] = temp;
          p++;
          q--;
        }
      }
    }

    void rotate(vector<vector<int>>& matrix) {
      transpose(matrix);
      reverseRows(matrix);
    }
};
