class Solution {
  public:
    string longestPalindrome(string s) {
      int size = s.size();
      if (!size) return s;
      vector<vector<bool>> DP(size, vector<bool>(size, false));
      int retval = 0;
      int idx = 0;
      for (int i = 0; i < size; i++) {
        DP[i][i] = true;
        retval = 1;
        idx = i;
      }
      for (int L = 2; L <= size; L++) {
        for (int i = 0, j = L-1; j < size; i++,j++) {
          if (L == 2 && s[i] == s[j]) {
            DP[i][j] = true;
            if (retval < j-i+1) {
              retval = j-i+1;
              idx = i;
            }
          } else if (DP[i+1][j-1] == true && s[i] == s[j]) {
            DP[i][j] = true;
            if (retval < j-i+1) {
              retval = j-i+1;
              idx = i;
            }
          }
        }
      }
      return s.substr(idx, retval);
    }
};
