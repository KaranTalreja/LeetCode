class Solution {
  public:
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> retval;
      if (!numRows) return retval;
      retval.push_back(vector<int>(1,1));
      for (int i = 1; i < numRows; i++) {
        vector<int> row(i+1,1);
        for (int j = i-1; j >= 1; j--) {
          row[j] = retval[i-1][j] + retval[i-1][j-1];
        }
        retval.push_back(row);
      }
      return retval;
    }
};
