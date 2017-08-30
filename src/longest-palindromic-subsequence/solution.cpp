class Solution {
  public:
    int max (int a, int b) {
      return a > b ? a : b;
    }

    int LCS(string& s, string& rev) {
      int size = s.size();
      vector<vector<int>> DP(size+1,vector<int>(size+1,0));
      for (int i = 1; i < size+1; i++) {
        for (int j = 1; j < size+1; j++) {
          if (s[i-1] == rev[j-1]) {
            DP[i][j] = DP[i-1][j-1] + 1;
          } else {
            DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
          }
        }
      }
      return DP[size][size];
    }

    int longestPalindromeSubseq(string s) {
      int size = s.size();
      if (size <= 1) return size;
      string rev = s;
      int i = 0;
      int j = size -1;
      while (i < j) {
        char temp = rev[i];
        rev[i] = rev[j];
        rev[j] = temp;
        i++;
        j--;
      }
      return LCS(s, rev);
    }
};
