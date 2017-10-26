class Solution {
  public:
    int countSubstrings(string s) {
      int size = s.size();
      if (!size) return 0;
      vector<vector<bool>> DP(size, vector<bool>(size, false));
      int retval = 0;
      for (int i = 0; i < size; i++) {
        DP[i][i] = true;
        retval++;
      }
      for (int L = 2; L <= size; L++) {
        for (int i = 0, j = L-1; j < size; j++, i++) {
          if (L == 2) {
            if (s[i] == s[j]) { DP[i][j] = true; retval++; }
          }
          else if (DP[i+1][j-1] == true && s[i] == s[j]) {DP[i][j] = true; retval++;}
        }
      }
      return retval;
    }
};
