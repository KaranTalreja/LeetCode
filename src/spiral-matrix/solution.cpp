class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int> retval;
      int rows = matrix.size();
      if (0 == rows) return retval;
      int columns = matrix[0].size();
      int i = 0, j = 0;
      int min_row = -1;
      int min_col = -1;
      bool updateCol = true;
      bool incrIdx = true;
      while (i < rows && j < columns && i > min_row && j > min_col) {
        retval.push_back(matrix[i][j]);
        if (true == updateCol) {
          if (true == incrIdx) {
            if (j == columns-1) {
              updateCol = !updateCol;
              if (i == rows-1) break;
              else {
                i++;
                min_row++;
              }
            } else j++;
          } else {
            if (j == min_col+1) {
              updateCol = !updateCol;
              if (i == min_row+1) break;
              else {
                i--;
                rows--;
              }
            } else j--;
          }
        } else {
          if (true == incrIdx) {
            if (i == rows-1) {
              updateCol = !updateCol;
              incrIdx = !incrIdx;
              if (j == min_col+1) break;
              else {
                j--;
                columns--;
              }
            } else i++;
          } else {
            if (i == min_row+1) {
              updateCol = !updateCol;
              incrIdx = !incrIdx;
              if (j == columns-1) break;
              else {
                j++;
                min_col++;
              }
            } else i--;
          }
        }
      }
      return retval;
    }
};
