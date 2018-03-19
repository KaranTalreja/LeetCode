class Solution {
  public:

    bool isValid(int r, int c, int i, int j) {
      if (i < 0 || i >= r || j < 0 || j >= c) return false;
      return true;
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
      vector<vector<int>> options = {{-1,-1},
        { 0,-1},
        { 1,-1},
        {-1, 0},
        { 1, 0},
        {-1, 1},
        { 0, 1},
        { 1, 1},
        { 0, 0}};
      int r = M.size();
      if(!r) return M;
      int c = M[0].size();
      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
          int sum = 0, count = 0;
          for(auto o : options) {
            if (isValid(r,c,i + o[0],j + o[1])) {
              count++;
              sum += (M[i + o[0]][j + o[1]] % 256);
            }
          }
          M[i][j] |= (sum / count) << 8;
        }
      }
      for (int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
          M[i][j] >>= 8;
        }
      }
      return M;
    }
};
