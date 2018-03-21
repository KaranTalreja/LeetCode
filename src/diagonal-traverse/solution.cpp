class Solution {
  public:
    bool isValid (int i, int j, int& R, int& C) {
      if (i < 0 || i >= R || j < 0 || j >= C) return false;
      return true;
    }

    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
      vector<vector<int>> options = {{+1, -1}, {-1, +1}}; // down, up
      int up = 1;
      int i = 0, j = 0;
      vector<int> retval;
      int R = matrix.size();
      if (!R) return retval;
      int C = matrix[0].size();
      while (i < R && j < C) {
        retval.push_back(matrix[i][j]);
        if (true == up) {
          if (isValid(i + options[up][0], j + options[up][1], R, C)) {
            i += options[up][0];
            j += options[up][1];
          } else {
            if (j + options[up][up] < C) j += options[up][up];
            else i += options[up][up];
            up = !up;
          }
        } else {
          if (isValid(i + options[up][0], j + options[up][1], R, C)) {
            i += options[up][0];
            j += options[up][1];
          } else {
            if (i + options[up][up] < R) i += options[up][up];
            else j+= options[up][up];
            up = !up;
          }
        }
      }
      return retval;
    }
};
