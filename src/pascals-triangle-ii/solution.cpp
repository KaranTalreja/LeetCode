class Solution {
  public:
    vector<int> getRow(int rowIndex) {
      vector<int> retval(rowIndex+1, 1);
      for (int j = 1; j < rowIndex; j++) {
        for (int i = j; i >= 1 ; i--) {
          retval[i] = retval[i] + retval[i-1];
        }
      }
      return retval;
    }
};
