class Solution {
  public:
    int minDistance(string s, string t) {
      int m = s.size();
      int n = t.size();
      vector<vector<int>> DP(m+1, vector<int> (n+1, -1));
      for (int i = 0; i <= m; i++) DP[i][0] = i;
      for (int i = 0; i <= n; i++) DP[0][i] = i;
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (s[i] == t[j]) DP[i+1][j+1] = DP[i][j];
          else {
            DP[i+1][j+1] = min(min(DP[i+1][j], DP[i][j+1]), DP[i][j]) + 1;
          }
        }
      }
      // for (auto x : DP) {
      //     for (auto y : x) {
      //         cout << y << " ";
      //     }
      //     cout << endl;
      // }
      return DP[m][n];
    }
};
