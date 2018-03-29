class Solution {
  public:
    bool isMatch(string s, string p) {
      int M = s.size();
      int N = p.size();
      vector<vector<bool>> DP(M+1, vector<bool>(N+1, false));
      DP[0][0] = true;
      for (int j = 0; j < N; j++) { // to match empty strings
        if (p[j] == '*') DP[0][j+1] = DP[0][j-1];
      }
      for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
          if (s[i] == p[j] || p[j] == '.') {
            DP[i+1][j+1] = DP[i][j];
          } else if (p[j] == '*') {
            bool rc = false;
            int k = i;
            while (!rc && (k >= 0) && (s[k] == p[j-1] || p[j-1] == '.')) { // one or more
              rc |= DP[k][j-1]; // One match.
              k--;
            }
            rc |= DP[i+1][j-1]; // Zero match
            DP[i+1][j+1] = rc;
          }
        }
      }
      // for (auto r : DP) {
      //     for (auto b : r) {
      //         cout << b << " ";
      //     }
      //     cout << endl;
      // }
      return DP[M][N];
    }
};
