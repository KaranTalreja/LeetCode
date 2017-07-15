class Solution {
  public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
      int row = nums.size();
      if (!row) return nums;
      int col = nums[0].size();
      if (row*col != r*c) return nums;
      vector<vector<int>> retval(r,vector<int>(c,0));
      int Rout = 0;
      int Cout = 0;
      for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
          retval[Rout][Cout] = nums[i][j];
          Cout++;
          if (Cout >= c) {
            Cout = 0;
            Rout++;
          }
        }
      }
      return retval;
    }
};
